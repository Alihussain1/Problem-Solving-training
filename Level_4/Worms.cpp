//https://codeforces.com/problemset/problem/474/B
#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 5;
long Piles[N];


int binarySearch(long arr[], int l, int r, long x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x || (x < arr[mid] && x > arr[mid-1] ) )
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}


int main()
{
	int n;
	cin >> n;
	long ai;
	cin >> ai;
	Piles[0] = ai;
	for (int i = 1; i < n; i++) {
		cin >> ai;
		Piles[i] = Piles[i - 1] + ai;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ai;
		cout << binarySearch(Piles,0,n,ai)+1 << endl;
	}
	return 0;
}