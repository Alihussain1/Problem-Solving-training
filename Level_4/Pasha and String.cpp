//https://codeforces.com/problemset/problem/525/B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int Freq[N];

int main()
{
	int n,m;
	string pasha;
	getline(cin, pasha);
	m = pasha.length();
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		Freq[x]++;
	}
	for (int i = 1; i <= m / 2; i++) {
		Freq[i] += Freq[i - 1];
	}
	for (int i = 1; i < pasha.length(); i++) {
		if (Freq[i] % 2 != 0) {
			swap(pasha[i-1], pasha[m - i]);
		}
	}
	cout << pasha << endl;
	return 0;
}