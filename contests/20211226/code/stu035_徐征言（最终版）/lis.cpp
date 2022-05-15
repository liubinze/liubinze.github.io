#include<bits/stdc++.h>
using namespace std;
int n,m,x[5005],h[5005],l[5005],ans;
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int a=1;a<=n;a++) scanf("%d",&x[a]);
	x[n+1]=1e9;
	for(int a=n;a>=1;a--)
	{
		for(int b=a+1;b<=n+1;b++)
		{
			if(x[a]<x[b])
			{
				if(h[a]<h[b]+1) h[a]=h[b]+1,l[a]=b;
				else if(h[a]==h[b]+1&&x[l[a]]<x[b]) l[a]=b;
			}
		}
	}
	for(int a=1;a<=n;a++)
	{
		if(h[a]>h[ans]||(h[a]==h[ans]&&x[a]>x[ans])) ans=a;
	}
	printf("%d\n",h[ans]);
	for(int a=ans;a<=n;a=l[a]) printf("%d ",x[a]);
}
