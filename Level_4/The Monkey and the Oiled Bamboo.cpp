#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;
long long n, C, S[N];
string X, Y;

bool CanWeMakeIt(long long k) {
	if (S[0] == k)
		k--;
	else if (S[0] > k)
		return 0;

	if (k < 0) return 0;
	for (int i = 1; i < n; i++)
	{
		if (S[i] - S[i - 1] == k)
			k--;
		else if (S[i] - S[i - 1] > k)
			return 0;
		if (k < 0) return 0;
	}
	return 1;
}

long long binarySearch() {
	long long lo = 0, mid, hi = S[n - 1] + 1;
	while (lo < hi) {
		mid = (lo + hi ) / 2;
		if (CanWeMakeIt(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main()
{
	int T;
	int indx = 1;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) { cin >> S[i]; }
		//sort(S, S + n);
		cout << "Case "<<indx<<": "<< binarySearch() << endl;
		indx++;
	}
	return 0;
}