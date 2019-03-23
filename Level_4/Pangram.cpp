//https://codeforces.com/problemset/problem/520/A
#include <iostream>
#include <string>
using namespace std;


int FREQ[26];

int main()
{
	int n;
	cin >> n;
	if (n < 26) {
		cout << "NO\n";
		return 0;
	}
	char x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x >= 'A' && x <= 'Z') { x += -'A' + 'a'; }
		FREQ[x - 'a'] = 1;
		}
	for (int i = 0; i < 26; i++) {
		if (FREQ[i] == 0) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}