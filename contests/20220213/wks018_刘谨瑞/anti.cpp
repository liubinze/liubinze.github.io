#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int T;
ULL n,k,maxn;
ULL function(ULL n)
{
	ULL x;
	for(int i=0;;i++)
	{
		if(n&(1<<i))
		{
			x=(1<<i);
			break;
		}
	}
	return (((n+x)&maxn)|((n^((n+x)&maxn))/x)>>2)&maxn;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%llu%llu",&n,&k);
		maxn=0;
		for(int i=k-1;i>=0;i--)
		{
			maxn+=(1<<i);
		}
		printf("%llu\n",function(n));
	}
	return 0;
}
