#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000111],dp[10000001],n,f[100000];
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				if(f[i]<f[j])
				if(f[i]==f[j])	
			}
			if(a[i]==a[j])
		}
		f[i]++;
	}
}
