#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],ln[5005],ans,k;
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ln[a[i]]=a[i];	
	}
	for(int i=n;i>1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]<a[i])
			{
				if(b[j]<b[i]+1)
				{
					b[j]=b[i]+1;
					ln[a[j]]=a[i];
				}
				else if(b[j]==b[i]+1)
				{
					ln[a[j]]=max(ln[a[j]],a[i]);
				}
			}
			ans=max(ans,b[j]);
		}
	}
	cout << ans+1 << endl;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==ans)
		{
			k=max(k,a[i]);
		}
	}
	for(int i=1;i<=ans+1;i++)
	{
		cout << k << " ";
		k=ln[k];
	}
	return 0;
}
