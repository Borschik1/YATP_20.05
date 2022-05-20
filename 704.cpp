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
    
    int n, m, x, y, p;
    float mid_x, mid_y, a, b, c;
    bool ok = true;
    fin >> n >> m;
    vector<pair<int, int>> vec;
    pair<int, int> plug;
    for (int i = 0; i < m; ++i) {
        fin >> x >> y;
        plug.first = x;
        plug.second = y;
        vec.push_back(plug);
    }
    mid_x = (float) n / 2;
    mid_y = (float) n / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == mid_x && j == mid_y) {
                continue;
            }
            a = j - mid_y;
            b = -i + mid_x;
            c = -mid_x * (j - mid_y) + -mid_y * (-i + mid_x);
            if (a * vec[0].first + b * vec[0].second + c > 0) {
                p = 1;
            }
            else if (a * vec[0].first + b * vec[0].second + c < 0) {
                p = -1;
            }
            else {
                continue;
            }
            ok = true;
            for (int f = 1; f < m; ++f) {
                if (p == 1) {
                    if (a * vec[f].first + b * vec[f].second + c <= 0) {
                        ok = false;
                        break;
                    }
                }
                else {
                    if (a * vec[f].first + b * vec[f].second + c >= 0) {
                        ok = false;
                        break;
                    }
                }

            }
            if (ok) {
                fout << "YES";
                return 0;
            }

        }
    }
    fout << "NO";

    fin.close();
    fout.close();
    system("pause");
    return 0;
}

