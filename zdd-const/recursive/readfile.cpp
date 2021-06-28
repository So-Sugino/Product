#ifndef rec_readfile_cpp
#define rec_readfile_cpp

#include "readfile.hpp"

queue<int> q_0;
extern vector<vector<int> > combi_set;
extern vector<queue<int> > divide_point;

/*
the function below is to read a file which has the combination as the sequence of numbers.
(ex. 1 2 7 15 18 -> {1,2,7,15,18})
*/
void readfile_fast(char *filename)
{
    ifstream reading_file(filename);
    if( reading_file.fail() )  throw "\033[31mIMPORT FAILED. INVALID FILENAME OR INCORRECT PATH.\033[m"; // if cannot read

    vector<int> combi_buffer;
    vector<char> item_buffer;
    /*
    combi_buffer : to keep the item in combination until finish reading all item in the combination
    item_buffer : to manipulate the sequence of numbers (1-character) as one number (ex. '1''2' -> 12)
    */
    bool flag = true;
    
    char c;
    while( reading_file.get(c) )
    { 
        if(c=='\n')
        {
            if(!item_buffer.empty())
            {
                string item_str(item_buffer.begin(),item_buffer.end());
                int item = stoi(item_str);
                combi_buffer.push_back(item);
                while ( combi_buffer.size() > divide_point.size() ){ divide_point.push_back(q_0); }
                if( (!combi_set.empty() && flag) && (combi_set.back().size() < combi_buffer.size() || combi_set.back().at(combi_buffer.size()-1) != item) )
                {
                    divide_point.at(combi_buffer.size()-1).push(combi_set.size());
                    flag = !flag;
                }
                item_buffer.clear();
            }
            combi_set.push_back(combi_buffer);
            flag = true;
            combi_buffer.clear();
        }
        else if(isspace(c))
        {

            string item_str(item_buffer.begin(),item_buffer.end());
            int item = stoi(item_str);
            combi_buffer.push_back(item);
            while ( combi_buffer.size() > divide_point.size() ) { divide_point.push_back(q_0); }
            if( (!combi_set.empty() && flag) && (combi_set.back().size() < combi_buffer.size() || combi_set.back().at(combi_buffer.size()-1) != item) )
            {
                divide_point.at(combi_buffer.size()-1).push(combi_set.size());
                flag = !flag;
            }
            item_buffer.clear();
        }
        else
        {
            item_buffer.push_back(c);
        }
    }
    if(!combi_buffer.empty())
    {
        if(!item_buffer.empty())
        {
            string item_str(item_buffer.begin(),item_buffer.end());
            int item = stoi(item_str);
            combi_buffer.push_back(item);
            while ( combi_buffer.size() > divide_point.size() ) divide_point.push_back(q_0);
            if( (!combi_set.empty() && flag) && (combi_set.back().size() < combi_buffer.size() || combi_set.back().at(combi_buffer.size()-1) != item) )
            {
                divide_point.at(combi_buffer.size()-1).push(combi_set.size());
                flag = !flag;
            }
            item_buffer.clear();
        }
        combi_set.push_back(combi_buffer);
        flag = true;
        combi_buffer.clear();
    }
    return;
}

void print_div(vector<queue<int> > queue_vector)
{
    vector<queue<int> > queue_vector_buffer = queue_vector;
    for (auto &q_buf : queue_vector_buffer )
    {
        while ( !q_buf.empty() )
        {
            cout << q_buf.front() << " ";
            q_buf.pop();
        }
        cout << endl;
    }
}

void print_set(vector<vector<int> > vector_vector)
{
    vector<vector<int> > vector_vector_buffer = vector_vector;
    for (auto &v_buf : vector_vector_buffer )
    {
        for (int l=0; l < v_buf.size(); l++ )
        {
            cout << v_buf.at(l) << " ";
        }
        cout << endl;
    }
}

#endif