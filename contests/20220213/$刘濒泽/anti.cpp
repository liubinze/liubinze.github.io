#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
inline ull func(ull n,ull k)
{
	ull x=n&-n;
	return (n+x&(1ull<<k)-1ull|((n^(n+x&(1ull<<k)-1ull))&(1ull<<k)-1ull)/x>>2ull)&(1ull<<k)-1ull;
}
int main()
{
	freopen("anti.in","r",stdin),freopen("anti.out","w",stdout);
	ull t,n,k;
	scanf("%llu",&t);
	while(t--)
		scanf("%llu%llu",&n,&k),printf("%llu\n",func(n&(1ull<<k)-1ull,k));
	return 0;
}
