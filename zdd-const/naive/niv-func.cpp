#ifndef niv_func_cpp
#define niv_func_cpp

#include "niv-func.hpp"

extern vector<vector<int> > combi_set;
ZBDD construct_one(int combi_index, int ord_num)
{
    ZBDD F = ZBDD(1);
    vector<int> combi = combi_set.at(combi_index);
    for(int i=combi.size()-1; i>=ord_num; i-- ) F = F.Change(combi.at(i));
    return F;
}

ZBDD construct_set()
{
    ZBDD R = ZBDD(0);
    for(int i=combi_set.size()-1; i>=0; i--)
    {
        R += construct_one(i,0);
    }
    return R;
}

#endif