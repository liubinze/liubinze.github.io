#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1000001],Xor[1000001],s,p;
int main()
{
	freopen("xor.in","r",stdin),
	freopen("xor.out","w",stdout);
	ll n,m,b;
	scanf("%lld%lld",&n,&m),p=n-1ll;
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i);
	for(ll i=0ll;i<n;i++)
		Xor[i]=e[i]^e[(i+1)%n],s+=Xor[i];
	printf("%lld",s-Xor[p]);
	while(m--)
		scanf("%lld",&b),printf(" %lld",s-Xor[p=(p+n-b%n)%n]);
	return 0;
}
