#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dad[2000001];
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
int main()
{
	freopen("liar.in","r",stdin),freopen("liar.out","w",stdout);
	ll n,m,op,x,y;
	scanf("%lld%lld",&n,&m),iota(dad,dad+2000001,0);
	while(m--)
	{
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op<1ll)
			dad[getdad(x)]=getdad(y),dad[getdad(x+n)]=getdad(y+n);
		else if(op<3ll)
			dad[getdad(x)]=getdad(y+n),dad[getdad(x+n)]=getdad(y);
		else if(getdad(x)^getdad(y)&&getdad(x+n)^getdad(y+n))
			puts("0");
		else
			puts("1"),dad[dad[x]]=dad[y],dad[dad[x+n]]=dad[y+n];
	}
	return 0;
}
