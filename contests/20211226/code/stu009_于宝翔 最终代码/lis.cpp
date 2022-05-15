#include<bits/stdc++.h>
using namespace std;

const int N=5005;

int n,len,idx;
int a[N],f[N],last[N],ans[N],temp[N];

void solve(int x)
{
	temp[++idx]=a[x];
	if(last[x])solve(last[x]);
}

void cmp()
{
	reverse(temp+1,temp+idx+1);
	for(int i=1;i<=idx;i++)
	{
		if(ans[i]>temp[i])return;
		if(temp[i]>ans[i])
		{
			for(int i=1;i<=idx;i++)
			{
				ans[i]=temp[i];
			}
			return;
		}
	}
}

int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(a[j]<a[i])
			{
				if(f[j]+1>f[i])
				{
					f[i]=f[j]+1;
					last[i]=j;
				}
				else if(f[j]+1==f[i]&&a[j]>a[last[i]])
				{
					f[i]=f[j]+1;
					last[i]=j;
				}
			}
	for(int i=1;i<=n;i++)
	{
		len=max(len,f[i]);
	}
	for(int i=1;i<=n;i++)
		if(f[i]==len)
			idx=0,solve(i),cmp();
	printf("%d\n",len);
	for(int i=1;i<=len;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
