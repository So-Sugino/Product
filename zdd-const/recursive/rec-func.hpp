#ifndef rec_func_hpp
#define rec_func_hpp

// include file for manipulate strings
#include <cstdio>
#include <stdio.h>

// include file for manipulate strings
#include <vector>
#include <queue>

// include ZBDD file
#include "ZBDD.h"

using namespace std;

ZBDD construct_one(int combi_index, int ord_num);

ZBDD construct_set(int start, int end, int ord);

#endif