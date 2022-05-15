#include<bits/stdc++.h>
using namespace std;
int q;
long long l,r,ll,rr,lk[10],rk[10];
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	for(int i=1;i<=9;i++)
	{
		lk[i]=(19-i)*i/2;
		rk[i]=(i+1)*i/2;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		ll=((l-1)/9+1)*9;
		rr=r/9*9;
		printf("%lld\n",(rr-ll)*5+lk[ll-l+1]+rk[r-rr]);
	}
	return 0;
}
//f(n)=(n-1)%9+1
