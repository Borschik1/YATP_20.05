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


void print(ofstream& out, const vector <long long>& vec) {
    for (auto c : vec) { out << c << " "; }
    out << endl;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    char c;
    long long n, t = 1, r = 0;
    fin >> c >> n;
    vector <long long> L, R;
    while (n > 0)
    {
        r = n % 3;
        if (r == 2) {
            L.push_back(t);
            n += 3;
        }
        else if (r == 1)
            R.push_back(t);
        t *= 3;
        n /= 3;
    }
    if (c == 'L')
    {
        fout << "L:";
        for (auto c : L) { fout << c << " "; }
        fout << endl;
        fout << "R:";
        for (auto c : R) { fout << c << " "; }
        fout << endl;
    }
    else
    {
        fout << "L:";
        for (auto c : R) { fout << c << " "; }
        fout << endl;
        fout << "R:";
        for (auto c : L) { fout << c << " "; }
        fout << endl;
    }

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

