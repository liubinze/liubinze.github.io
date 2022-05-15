#include<bits/stdc++.h>
#define int long long
using namespace std;

int t;
int l,r,ans;

int s(int x)
{
	int t=0;
	while(x)
	{
		t+=x%10;
		x/=10;
	}
	if(t>=10)return s(t);
	else return t;
}

signed main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		int d=r-l+1,k=d/9;
		ans+=k*45;
		d=d-k*9;
		int temp;
		temp=s(l);
		for(int i=1;i<=d;i++,temp++)
		{
			temp%=10;
			if(temp==0)temp=1;
			ans+=temp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
