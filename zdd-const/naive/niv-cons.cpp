// include header files
#include "readfile.hpp"
#include "niv-func.hpp"
#include <chrono>

vector<vector<int> > combi_set;
vector<queue<int> > divide_point;

int main(int argc, char** argv)
{
    try
    {
        combi_set.clear(); divide_point.clear();
        if( argv == NULL ) throw "No arguments is supplied. Please give one filename.";
        BDD_Init(65536,8388608);
        for(int i=0; i<20000; i++) BDD_NewVarOfLev(1);

        chrono::system_clock::time_point  start, end; // 型は auto で可
        start = chrono::system_clock::now(); // 計測開始時間

        readfile_fast(argv[1]);
        // cout << "\033[36m +SUCCESSFULLY READ! \033[m" << endl;
        
        // print_set(combi_set);

        ZBDD R = construct_set();
        // cout << "\033[36m +SUCCESSFULLY CONSTRUCTED! \033[m" << endl;

        end = chrono::system_clock::now();  // 計測終了時間
        double t = chrono::duration_cast<std::chrono::microseconds>(end-start).count();

        R.Print();
        cout << t << endl;
    }
    catch (char *err)
    {
        cerr << err << endl;
    }

}