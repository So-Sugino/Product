#ifndef rec_func_cpp
#define rec_func_cpp

#include "rec-func.hpp"

extern vector<vector<int> > combi_set;
ZBDD construct_one(int combi_index, int ord_num)
{
    ZBDD F = ZBDD(1);
    vector<int> combi = combi_set.at(combi_index);
    for(int i=combi.size()-1; i>=ord_num; i-- ) F = F.Change(combi.at(i));
    return F;
}

extern vector<queue<int> > divide_point;
ZBDD construct_set(int start, int end, int ord)
{
    if( start==end ) return construct_one(start, ord);
    else if ( combi_set.at(start).size() < ord+1 )
    {
        if( divide_point.at(ord).empty() ) return construct_set( start, end, ord+1 );
        int partition = divide_point.at(ord).front();
        if( partition > end || partition < start ) return construct_set( start, end, ord+1 );
        else
        {
            divide_point.at(ord).pop();
            return ZBDD(1)+construct_set(partition, end, ord);
        }
    }
    else
    {
        int item_val = combi_set.at(start).at(ord);
        if( divide_point.at(ord).empty() ) return construct_set( start, end, ord+1 ).Change(item_val);
        int partition = divide_point.at(ord).front();
        if( partition > end || partition < start ) return construct_set( start, end, ord+1 ).Change(item_val);
        else
        {
            divide_point.at(ord).pop();
            return construct_set(start, partition-1, ord+1).Change(item_val) + construct_set(partition, end, ord);
        }
    }
}

#endif