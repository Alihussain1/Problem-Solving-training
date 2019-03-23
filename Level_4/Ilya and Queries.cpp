//https://codeforces.com/problemset/problem/313/B
#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 5;
char str[N];
int sum[N];
int main()
{	
	int Q;
	string x;
	getline(cin, x);
	sum[0] = 0;
	for (int i = 1; i < x.length(); i++) {
		if (x[i] == x[i - 1]) {
			sum[i] = sum[i - 1]+1;
		}
		else {
			sum[i] = sum[i - 1];
		}
	}
	cin >> Q;
	int i, j;
	while (Q--) {
		cin >> i >> j;
		cout << sum[j - 1] - sum[i - 1] << endl;
	}
	return 0;
}