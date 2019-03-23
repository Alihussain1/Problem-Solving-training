//https://codeforces.com/contest/17/problem/A
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 6;


int Arr[N];



inline ll FixMod(ll a, ll b)
{
	return ((a%b) + b) % b;
}
inline ll Floor(ll a, ll b)
{
	return ((a - FixMod(a, b)) / b);
}
inline ll GetDivisors(ll n)
{
	//vector<ll> div;
	ll count = 0;
	ll i = 0;
	for (i = 1; i*i < n; i++) {
		if (n%i == 0)
		{
			//div.push_back(i);
			//div.push_back(n/i);
			count += 2;
		}
	}
	if (i*i == n)
		count++;//div.push_back(i);
	return count;
}
inline bool Is_Prime(ll n)
{
	if (n <= 1)return false;
	if (n <= 3)return true;
	if (FixMod(n, 2) == 0 || FixMod(n, 3) == 0)return false;
	for (ll i = 0; i*i <= n; i += 6)
	{
		if (FixMod(n, i) == 0) return false;
	}
	return true;
}


bitset<N> is_prime;

vector<ll> ff;
void sieve() {   
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	ll LastPrime = 2;
	for (ll i = 2; i <= 1500; ++i)
		if (is_prime[i]) {
			if (is_prime[i + LastPrime + 1])
				ff.push_back(i + LastPrime + 1);
			LastPrime = i;
			for (ll j = i * i; j < N; j += i)
				is_prime[j] = 0;
		}
}

int main()
{
	sieve();
	int n, k;
	cin >> n >> k;
	if (k == 0)
	{
		cout << "YES\n";
		return 0;
	}
	/*for (int i = 0; i < 25; i++)
	{
		cout << ff[i] << " , ";
	}*/
	if (upper_bound(ff.begin(), ff.end(), n) - ff.begin() - 1 >= k)
	{

		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}