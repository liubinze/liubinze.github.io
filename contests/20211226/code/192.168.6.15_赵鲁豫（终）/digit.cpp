#include<iostream>
using namespace std;
long long q;
long long f[2005];
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		long long l,r,l1,r1,c,ans;
		scanf("%lld%lld",&l,&r);
		l1=l%9,r1=r%9;
		if(l1==0)l1=9;
		if(r1==0)r1=9;
		c=r-l+1;
		ans=c/9*45;
		if(c%9!=0)
		{
			if(r1<l1)
			{
				for(int i=l1;i<=9;i++)
					ans+=i;
				for(int i=1;i<=r1;i++)
					ans+=i;
			}
			else
			{
				for(int i=l1;i<=r1;i++)
					ans+=i;
			}
		}
		printf("%lld\n",ans);
	}
}

