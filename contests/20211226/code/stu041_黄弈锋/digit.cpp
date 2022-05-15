#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[100000005];
ll t, l, r, ans;

int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%lld",&t);
	for(int i = 1; i <= 1e8; i++)
	{
		if(i < 10) f[i] = i;
		if(i >= 10)
		{
			f[i] = i % 9;
			if(f[i] == 0) f[i] = 9;
		}
	}
	while(t--)
	{
		scanf("%lld %lld",&l,&r);
		ans = 0;
		for(int i = l; i <= r; i++)
		{
			ans += f[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4
9 13
44 45
1998 2018
1122334455 6677889900
*/
