#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int b;
    fin >> b;
    if (b == 2 || b == 3 || b == 6) {
        fout << -1;
        return 0;
    }
    if (b == 4) {
        fout << 2 << endl << 1 << endl << 0 << endl << 1;
        return 0;
    }
    if (b == 5) {
        fout << 1 << endl << 2 << endl << 0 << endl << 0 << endl << 2;
        return 0;
    }
    else {
        fout << 2 << endl << 1 << endl;
        for (int i = 0; i < b - 7; ++i) {
            fout << 0 << endl;
        }
        fout << 1 << endl << 0 << endl << 0 << endl << 0 << endl << b - 4 << endl;
        return 0;
    }
    fin.close();
    fout.close();
    system("pause");
    return 0;
}

