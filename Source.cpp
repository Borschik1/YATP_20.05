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
    
    map<int, long long> mp;
    mp.emplace(2, 1);
    int k, p;
    fin >> k >> p;
    if (k == 1) {
        fout << 0;
        return 0;
    }
    for (int i = 3; i <= k; ++i) {
        if (i % 2 == 1) {
            mp.emplace(i, mp[i - 1] % p);
        }
        else {
            mp.emplace(i, (mp[i - 1] + mp[i / 2]) % p);
            mp.erase(i / 2);
        }
    }
    fout << mp[k];

    fin.close();
    fout.close();
    system("pause");
    return 0;
}

