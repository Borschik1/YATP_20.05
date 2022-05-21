#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;


bool EuclidAlgo(long long& a, long long& b, const long long& c, const long long& d) {
    if (a == c && b == d) { return true; }
    while (b != 0) {
        if (b > a) {
            swap(a, b);
            if (a == c && b == d) { return true; }
        }
        if (b > 0) {
            long long nSub = a / b;
            long long oldA = a;
            a -= a / b * b;
            long long newA = a;
            if (b == d && newA <= c && c <= oldA && (oldA - c) % b == 0) { return true; }
        }
    }
    return false;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int t;
    long long a, b, c, d;
    fin >> t;
    for (int i = 0; i < t; ++i) {
        fin >> a >> b >> c >> d;
        if (EuclidAlgo(a, b, c, d)) { fout << "YES" << endl; }
        else { fout << "NO" << endl; }
    }

    fin.close();
    fout.close();
    system("pause");
    return 0;
}

