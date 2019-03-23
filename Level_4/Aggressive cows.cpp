#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;
long long n, C, S[N];
string X, Y;
bool CanWeCoverIt(long long MinLen) {
	long long tmp = C;
	long long nextFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (S[i] - nextFree >= 0)
		{
			tmp--;
			nextFree = S[i] + MinLen;
		}
		if (tmp == 0) return 1;
	}
	if (tmp == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long long binarySearch() {
	long long lo = 0, mid, hi = S[n - 1] - S[0]+1;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		if (CanWeCoverIt(mid)) {
			lo = mid;
		}
		else {
			hi = mid-1;
		}
	}
	return lo;
}

int main()
{
	int T;

	cin >> T;
	while (T--) {
		cin >> n >> C;
		for (int i = 0; i < n; i++) { cin >> S[i]; }
		sort(S, S + n);
		cout << binarySearch() << endl;
	}
	return 0;
}