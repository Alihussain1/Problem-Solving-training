//https://codeforces.com/contest/271/problem/B
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;


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

vector<ll> primes;
void sieve() {   
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	ll i = 0;
	for (i = 2; i*i <= N; ++i)
		if (is_prime[i]) 
		{
			primes.push_back(i);
			for (ll j = i * i; j < N; j += i)
				is_prime[j] = 0;
		}
	for (i ; i < N; i++)
	{
		if (is_prime[i])
			primes.push_back(i);
	}
}
ll Mat[501][501];

int main()
{
	sieve();
	int n, m;
	cin >> n >> m;


	int ClosestPrimeIndx = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Mat[i][j];
			if (is_prime[Mat[i][j]])
				Mat[i][j] = -1;
			else
			{
				ClosestPrimeIndx = upper_bound(primes.begin(), primes.end(), Mat[i][j]) - primes.begin();
				Mat[i][j] = primes[ClosestPrimeIndx] - Mat[i][j];
			}
		}
	}
	//rows
	ll minSum = 1e5+1;
	for (int i = 0; i < n; i++)
	{
		ll sum = 0;
		for (int j = 0; j < m; j++)
		{
			if (Mat[i][j] != -1)
				sum += Mat[i][j];
		}
		if (sum < minSum)
		{
			minSum = sum;
		}
	}
	//cols
	for (int i = 0; i < m; i++)
	{
		ll sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (Mat[j][i] != -1)
				sum += Mat[j][i];
		}
		if (sum < minSum)
		{
			minSum = sum;
		}
	}
	cout << minSum << endl;
	return 0;
}