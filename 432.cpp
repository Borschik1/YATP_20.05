#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


vector<vector<char>> activate(vector<vector<char>> vec, int x, int y, int n, int m) {
    if (vec[x][y] != '#') {
        return vec;
    }
    vec[x][y] = '1';
    if (x + 1 < n) {
        if (vec[x + 1][y] == '#') {
            vec = activate(vec, x + 1, y, n, m);
        }
    }
    if (y - 1 >= 0) {
        if (vec[x][y - 1] == '#') {
            vec = activate(vec, x, y - 1, n, m);
        }
    }
    if (y + 1 < m) {
        if (vec[x][y + 1] == '#') {
            vec = activate(vec, x, y + 1, n, m);
        }
    }
    if (x - 1 >= 0) {
        if (vec[x - 1][y] == '#') {
            vec = activate(vec, x - 1, y, n, m);
        }
    }
    return vec;
}


void print(vector<vector<char>> vec, int n, int m) {
    for (int i = 0; i < n; ++i) {
        cout << endl;
        for (int j = 0; j < m; ++j) {
            cout << vec[i][j] << " ";
        }
    }
    cout << endl;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int n, m, cnt = 0;
    fin >> n >> m;
    char str;
    vector<vector<char>> vec;
    vector<char> plug;
    for (int i = 0; i < n; ++i) {
        plug.clear();
        for (int j = 0; j < m; ++j) {
            fin >> str;
            plug.push_back(str);
        }
        vec.push_back(plug);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == '#') {
                cnt++;
                vec = activate(vec, i, j, n, m);
                print(vec, n, m);
            }
        }
    }
    fout << cnt;


    fin.close();
    fout.close();
    system("pause");
    return 0;
}

