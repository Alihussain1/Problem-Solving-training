//https://codeforces.com/problemset/problem/433/B
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
long long Q1[N];

int main()
{
	long long n,tmp, m;
	cin >> n;
	vector<long long> Q2(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		Q1[i] = tmp + Q1[i - 1];
		Q2[i-1] = tmp;
	}
	sort(Q2.begin(),Q2.end());
	for (int i = 1; i < Q2.size(); i++) {
		Q2[i] += Q2[i - 1];
	}
	cin >> m;
	long long type, L, R;
	for (int i = 0; i < m; i++) {
		cin >> type>>L>> R;
		if (type == 1) {
			cout << Q1[R] - Q1[L - 1] << endl;
		}
		else {
			cout << Q2[R] - Q2[L - 1] << endl;
		}
	}
	return 0;
}