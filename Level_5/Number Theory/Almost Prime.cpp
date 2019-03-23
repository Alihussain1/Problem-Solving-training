//https://codeforces.com/contest/26/problem/A
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
const int N = 5000;
inline ll fixmod(ll a, ll b) {
	return ((a%b) + b) % b;
}
inline ll floor(ll a, ll b) {
	return (a - fixmod(a, b)) / b;
}

inline bool isPrime(ll a) {
	if (a <= 1) return false;
	if (a <= 3) return true;
	if (a % 2 == 0 || a % 3 == 0) return false;
	for (ll i = 5; i*i <= a; i += 6)
	{
		if (a%i == 0 || a % (i + 2) == 0)
			return false;
	}
	return true;
}
inline vector<ll> GetDivisors(ll a) {
	vector<ll> divisors;
	for (ll i = 1; i*i <= a; i++)
	{
		if (a%i == 0 && isPrime(i))
			divisors.push_back(i);
		if (a%i == 0 && isPrime(a / i) && ((a / i) != i))
			divisors.push_back(a / i);
	}
	return divisors;
}

int n;
int main()
{
	cin >> n;
	
	int count = 0;
	for (ll i = 6; i <= n; i++)
	{
		vector<ll>  div = GetDivisors(i);
		
		if (div.size() == 2) count++;
	}
	cout << count << endl;
}
