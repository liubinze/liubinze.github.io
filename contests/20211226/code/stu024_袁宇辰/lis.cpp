#include<bits/stdc++.h>
using namespace std;
int n,ans,k;
int a[5005],f[5005],path[5005];
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				if(f[i]<f[j])path[i]=j,f[i]=f[j];
				if(f[i]==f[j]&&a[path[i]]<a[j])path[i]=j;
			}
		}
		f[i]++;
		if(ans<f[i])ans=f[i],k=i;
		if(ans==f[i]&&a[k]<a[i])k=i;
	}
	printf("%d\n",ans);
	for(int i=k;i<=n&&i!=0;i=path[i])printf("%d ",a[i]);
	return 0;
}
