#include<bits/stdc++.h>
#define lll __int128
#define r register
#define ll long long
using namespace std;

__int128 func(__int128 n)
{
	__int128 x=n&-n;
	return (n+x)|((n^(n+x))/x)>>(__int128)2;
}

ll func32(ll n)
{
	ll x=n&-n;
	return (n+x)|((n^(n+x))/x)>>2ll;
}

inline lll read()
{
	r lll rt=0;
	r char gt=getchar();
	while(gt>'9'||gt<'0')
	{
		gt=getchar();
	}
	while(gt<='9'&&gt>='0')
	{
		rt=(rt<<(lll)1)+(rt<<(lll)3)+(gt^(lll)48);
		gt=getchar();
	}
	return rt;
}

inline void write(lll n)
{
	string ans="";
	while(n>0)
	{
		ans=(char)(n%10+('1'-1))+ans;
		n/=10;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	r int T;
	lll n;
	int k;
	scanf("%d",&T);
	while(T--)
	{
		n=read();
		scanf("%d",&k);
		if(k<=62) printf("%lld\n",func32((long long)n));
		else write(func(n));
	}
	exit(0);
}

