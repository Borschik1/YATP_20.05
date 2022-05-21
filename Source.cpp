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
typedef vector<int> vec;

istream& operator >>(istream& stream, vec& a) {
	string s; 
	stream >> s;
	for (int i = s.size() - 1; i >= 0; --i) { a.push_back(s[i] - '0'); }
	return stream;
}

ostream& operator <<(ostream& stream, vec a) {
	for (int i = a.size() - 1; i >= 0; --i) { stream << a[i]; }
	return stream;
}

bool operator >(vec a, vec b) {
	if (a.size() > b.size()) { return true; }
	if (a.size() < b.size()) { return false; }
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i] > b[i]) { return true; }
		if (a[i] < b[i]) { return false; }
	}
	return false;
}

vec operator +(vec a, vec b) {
	vec c; int i, r = 0;
	for (i = 0; i < a.size() || i < b.size(); ++i) {
		if (i < a.size()) { r += a[i]; }
		if (i < b.size()) { r += b[i]; }
		c.push_back(r % 10);
		r /= 10;
	}
	if (r) { c.push_back(r); };
	return c;
}

vec operator -(vec a, vec b) {
	vec c; int i, r = 0;
	for (i = 0; i < a.size(); ++i) {
		r += a[i];
		if (i < b.size()) { r -= b[i]; }
		if (r < 0) { c.push_back(r + 10); r = -1; }
		else { c.push_back(r % 10); r = 0; }
	}
	while (c.size() > 1 && c.back() == 0) { c.pop_back(); };
	return c;
}

vec operator *(vec a, long long b) {
	vec c; int i;
	long long r = 0;
	if (b == 0) { c.push_back(0); return c; }
	for (i = 0; i < a.size(); ++i) {
		r += a[i] * b;
		c.push_back(r % 10);
		r /= 10;
	}
	while (r) { c.push_back(r % 10); r /= 10; }
	return c;
}

vec operator /(vec a, long long b) {
	vec c; int i;
	long long r = 0, t;
	for (i = a.size() - 1; i >= 0; --i) {
		r = r * 10 + a[i]; 
		t = r / b;
		c.insert(c.begin(), t);
		r -= t * b;
	}
	while (c.size() > 1 && c[c.size() - 1] == 0) { c.resize(c.size() - 1); }
	return c;
}

long long operator % (vec a, long long b) {
	vec c; int i; long long r = 0, t;
	for (i = a.size() - 1; i >= 0; --i) {
		r = r * 10 + a[i]; t = r / b; r -= t * b;
	}
	while (c.size() > 1 && c[c.size() - 1] == 0) c.resize(c.size() - 1);
	return r;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
	vec a;
	long long b;
	fin >> a >> b;
	fout << a / b;

    fin.close();
    fout.close();
    system("pause");
    return 0;
}

