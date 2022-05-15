#include<bits/stdc++.h>
using namespace std;
int n,m,t;
long long l,r,ans;
long long digit(long long l)
{
	long long sum=l;
	while(sum>=10)
	{
		long long h=0;
		while(sum>0)
		{
			h+=sum%10;
			sum/=10;
		}
		sum=h;
	}
	return sum;
}
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		ans+=(r-l+1)/9*45;
		for(long long a=l+(r-l+1)/9*9;a<=r;a++) ans+=digit(a);
		printf("%lld\n",ans);
	}
}
