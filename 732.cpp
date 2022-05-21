#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;



int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    size_t n_ab, n_bc, n_ac;
    int n;
    fin >> n >> n_ab >> n_bc >> n_ac;
    vector<size_t> vec(6, 0);
    size_t temp = min(min(n_ab, n_bc), n_ac) / 2;
    for (int i = 0; i < 3; ++i) { vec[2 * i] = temp; }
    n_ab -= temp * 2;
    n_bc -= temp * 2;
    n_ac -= temp * 2;
    n -= temp * 3;
    n -= n_ab + n_bc + n_ac;
    vec[1] = n_ab;
    vec[3] = n_bc;
    vec[5] = n_ac;

    if (n_ab == 0 && n_bc == 0 && n_ac == 0 && n == 0) {
        fout << "YES" << endl;
        for (auto c : vec) { fout << c << " "; }
        return 0;
    }

    fout << "NO";


    fin.close();
    fout.close();
    system("pause");
    return 0;
}

