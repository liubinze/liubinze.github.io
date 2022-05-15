#include <bits/stdc++.h>
using namespace std;

int k;

unsigned int func1(unsigned int n) 
{
	unsigned int x = n & (-n);
	return (n + x) | ((n ^ (n + x)) / x) >> 2;
}

unsigned long long func2(unsigned long long n)
{
	unsigned long long x = n & (-n);
	return (n + x) | ((n ^ (n + x)) / x) >> 2;
}

int func3(int n,int k)
{
	int mod = 2 << k;
	unsigned int x = n & (-n);
	return (n + x) % mod | ((n ^ (n + x)) / x) % mod >> 2 % mod;
}

long long func4(long long n,long long k)
{
	long long mod = 2 << k;
	unsigned long long x = n & (-n);
	return (n + x) % mod | ((n ^ (n + x)) / x) % mod >> 2 % mod;
}

int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long tmp;
		scanf("%lld %d",&tmp,&k);
		if(k == 32)
		{
			unsigned int n = tmp;
			printf("%d\n",func1(n));
		}
		else if(k == 64)
		{
			unsigned long long n = tmp;
			printf("%lld\n",func2(n));
		}
		else if(k <= 32)
		{
			int n = tmp;
			printf("%d\n",func3(n,k));
		}
	}
	return 0;
}
