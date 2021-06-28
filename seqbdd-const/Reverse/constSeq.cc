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

void init(){
    variable.clear(); item.clear();
}

void readfile_fast(char *filename){
    ifstream reading_file(filename);
    char c;
    if(reading_file.fail()){ cerr << "Failed" << endl; }
    vector<int> item_buffer;
    while(reading_file.get(c)){
        if(c=='\n'){ item.push_back(item_buffer); item_buffer.clear(); continue;}
        item_buffer.push_back(variable[c]);
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

SeqBDD naive(){
    SeqBDD F = SeqBDD(0);
    for(int i=item.size()-1; i>=0; i--){
        F += construct(0,i);
        //cout << i+1 << " " << F.Size() << endl;
    }
    return F;
}

int main(int atgc, char** argv){

    init();
    
    BDDV_Init(65536,1048576);
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
    F = naive();
    e_make = chrono::system_clock::now();

    long double time_read = chrono::duration_cast<chrono::microseconds>(e_read-s_read).count();
    long double time_make = chrono::duration_cast<chrono::microseconds>(e_make-s_make).count();
    cout << fixed << setprecision(0) << time_read + time_make << " " << time_make << endl;
    // F.Print();
    // cout << "[ time:" << time_read + time_make << " time-to-read:" << time_read << " time-to-make:" << time_make << "]" << endl;
}