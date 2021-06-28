#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

#include <stdio.h>
#include <chrono>

#include <fstream>
#include <sstream>
#include <iomanip>

#include "SeqBDD.h"

using namespace std;

map<char,int> variable;
vector<vector<int> > item;
vector<queue<int> > pointer;

void init(){
    variable.clear(); item.clear(); pointer.clear();
}

void printPointer(){
    for(int i=0; i < pointer.size(); i++){
        queue<int> q = pointer.at(i);
        cout << "{ ";
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void readfile_fast(char *filename){
    ifstream reading_file(filename);
    char c;
    if(reading_file.fail()){ cerr << "Failed" << endl; }
    vector<int> item_buffer;
    vector<int> prev;
    int l, ci = 0;
    bool flag = true;
    while(reading_file.get(c)){
        if(c=='\n'){ 
            item.push_back(item_buffer);
            prev = item_buffer;
            item_buffer.clear();
            flag = true; ci++; l=0;
            continue;
        }
        int varnum = variable[c];
        item_buffer.push_back(varnum);
        if((l>=prev.size() || varnum!=prev.at(l)) && flag && ci!=0){
            while(pointer.size() < l+1){
                queue<int> q; pointer.push_back(q);
            }
            int p = item.size();
            pointer.at(l).push(p);
            flag = false;
        }
        l++;
    }
}

SeqBDD construct(int th, int start){
    SeqBDD G = SeqBDD(1);
    vector<int> v = item.at(start);
    for(int i=v.size()-1; i >= th; i--){
        int var = v.at(i);
        G = G.Push(var);
    }
    return G;
}

SeqBDD recursive(int th, int start, int end){
    if( start == end ){ return construct(th,start); }
    else if( item.at(start).size() <= th ){
        int div = pointer.at(th).front();
        if( div > end || div < start){ return recursive(th+1,start,end); }
        else {
            pointer.at(th).pop();
            return SeqBDD(1) + recursive(th,div,end);
        }
    }
    else {
        int val = item.at(start).at(th);
        if( pointer.at(th).empty() ){ return recursive(th+1,start,end).Push(val);}
        int div = pointer.at(th).front();
        if( div > end || div < start ){ return recursive(th+1,start,end).Push(val); }
        else {
            pointer.at(th).pop();
            return recursive(th+1,start,div-1).Push(val) + recursive(th,div,end);
        }
    }
}

void run(char** argv){

    init();
    
    BDDV_Init(65536,8388608);
    SeqBDD F = SeqBDD(0);

    for(int a=0; a<26; a++){
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        int varLevel = BDD_NewVarOfLev(1);
        variable[alphabets[a]] = varLevel;
    }


    chrono::system_clock::time_point s_read,e_read,s_make,e_make;

    s_read = chrono::system_clock::now();
    readfile_fast(argv[1]);
    e_read = chrono::system_clock::now();

    s_make = chrono::system_clock::now();
    F = recursive(0,0,item.size()-1);
    e_make = chrono::system_clock::now();

    long double time_read = chrono::duration_cast<chrono::microseconds>(e_read-s_read).count();
    long double time_make = chrono::duration_cast<chrono::microseconds>(e_make-s_make).count();

    cout << fixed << setprecision(0) << time_read + time_make << " " << time_make << endl;
    // cout << "[ time:" << time_read + time_make << " time-to-read:" << time_read << " time-to-make:" << time_make << "]" << endl;
    
    F.Print();
}

int main(int atgc, char** argv){
    run(argv);
}