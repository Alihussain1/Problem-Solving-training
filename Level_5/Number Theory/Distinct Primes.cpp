//https://www.spoj.com/problems/AMR11E/
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

bitset<N> is_prime;
vector<ll> primes;
vector<ll> luckyNum;
int SPF[N];
void sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i < N; i++)
	{
		if (i % 2 == 0 && i > 2) 
			SPF[i] = 2;
		else
			SPF[i] = i;
	}
	for (int i = 3; i*i <= N; i++)
	{
		if (is_prime[i])
			for (ll j = i * i; j < N; j += i)
			{
				is_prime[j] = 0; 
				if(SPF[j]==j)
					SPF[j] = i;
			}
	}
}

void IsLuckyNum()
{
	int count = 0;
	int n = 0;
	int last=-1;
	vector<int> tmp;
	for (int i = 29; i < 3000; i++)
	{
		count = 0;
		n = i;
		
		while (n != 1)
		{
			if(last!=SPF[n]) count++;
			last = SPF[n];//if(tmp)tmp.push_back(SPF[n]);
			n /= SPF[n];
			
			if (count >= 3)
			{
				luckyNum.push_back(i);
				n = 1;
			}
		}
	}
}


int main()
{
	sieve();
	IsLuckyNum();
	int T, x;
	cin >> T;
	
	while (T--)
	{
		cin >> x;		
		cout << luckyNum[x - 1] << endl;
	}
	return 0;
}