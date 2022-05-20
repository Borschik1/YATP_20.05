#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


void activate(vector<vector<int>> &vec, int x, int y, int n, int m) {
    if (vec[x][y] != 0) {
        return;
    }
    vec[x][y] = 1;
    if (x + 1 < n) {
        if (vec[x + 1][y] == 0) {
            activate(vec, x + 1, y, n, m);
        }
    }
    if (y - 1 >= 0) {
        if (vec[x][y - 1] == 0) {
            activate(vec, x, y - 1, n, m);
        }
    }
    if (y + 1 < m) {
        if (vec[x][y + 1] == 0) {
            activate(vec, x, y + 1, n, m);
        }
    }
    if (x - 1 >= 0) {
        if (vec[x - 1][y] == 0) {
            activate(vec, x - 1, y, n, m);
        }
    }
}


void print(vector<vector<int>> vec, int n, int m) {
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
    
    int n, m, cnt = 0, k, x, y;
    fin >> n >> m;
    char str;
    vector<vector<int>> vec;
    vector<int> plug;
    for (int i = 0; i < n; ++i) {
        plug.clear();
        for (int j = 0; j < m; ++j) {
            plug.push_back(0);
        }
        vec.push_back(plug);
    }
    fin >> k;
    for (int i = 0; i < k; ++i) {
        fin >> x >> y;
        vec[x - 1][y - 1] = 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == 0) {
                cnt++;
                activate(vec, i, j, n, m);
                //print(vec, n, m);
            }
        }
    }
    fout << cnt;


    fin.close();
    fout.close();
    system("pause");
    return 0;
}

