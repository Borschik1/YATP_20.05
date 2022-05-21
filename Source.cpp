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
    
    int n;
    fin >> n;
    long long answer = pow(3, n / 3);
    if (n % 3 == 1) {
        answer = answer * 4 / 3;
    }
    if (n % 3 == 2) {
        answer *= 2;
    }
    fout << answer;


    fin.close();
    fout.close();
    system("pause");
    return 0;
}

