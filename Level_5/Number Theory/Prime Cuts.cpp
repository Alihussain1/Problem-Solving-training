//https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=347
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

bitset<N> is_prime;
vector<ll> primes;

void sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	int i = 0;
	primes.push_back(1);
	for (i = 2; i*i <= N; i++)
	{
		if (is_prime[i])
			primes.push_back(i);
			for (ll j = i * i; j < N; j += i)
				is_prime[j] = 0;
	}
	for (i; i < 1010; i++)
		if (is_prime[i])
			primes.push_back(i);
}


int main()
{
	sieve();
	int n, c;
	int startIndx = 0,endindex=0;
	
	while (cin >> n >> c)
	{
		int lastElementIndx = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		if (c >= lastElementIndx) {
			startIndx = 0;
			endindex = lastElementIndx;
		}
		else
		{
			if (lastElementIndx % 2 == 0)
			{
				//even 2C
				startIndx = (lastElementIndx / 2) - c;
				endindex = (lastElementIndx / 2) + c;
				
			}
			else
			{
				//odd 2C-1
				startIndx = (lastElementIndx / 2) - (c - 1);
				endindex = (lastElementIndx / 2) + c;
			}
		}
		if (startIndx < 0) startIndx = 0;
		if (endindex > lastElementIndx) endindex = lastElementIndx;
		cout << n << " " << c << ": ";
		//loop
		for (int i = startIndx; i < endindex; i++)
		{
			cout << primes[i] << " \n"[(i + 1) == endindex];
		}
		cout << endl;
	}
	return 0;
}