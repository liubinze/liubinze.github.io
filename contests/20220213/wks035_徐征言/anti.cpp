#include<bits/stdc++.h>
using namespace std;
int t,k;
long long n;
unsigned long long func(unsigned long long n) {
unsigned long long x = n & (-n);
return (n + x) | ((n ^ (n + x)) / x) >> 2ll;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%d",&n,&k);
		printf("%lld\n",func(n));
	}
}


