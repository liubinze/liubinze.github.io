#include<bits/stdc++.h>
using namespace std;
bool used[5001];
int ans[1001][1001],max_,kl=0,k[2000];
int n,p[5000],m,kw;
void dfs(int now,int l,int a[2000])
{
	if(l==n-m)
	{kl++;
		for(int i=1;i<=n;i++)
		{
			
			ans[kl][i]=a[i];
		}
		return;
	}
	int k=l;
	for(int i=now+1;i<=n;i++)
	{
		dfs(now+1,l,a);	
		a[l+1]=p[i];
		l++;
	}
	for(int i=now+1;i<=n;i++)
	{
		a[k+1]=p[i];
		k++;
		dfs(now+1,k,a);	
	}			
}
int bijiao(int a[2000],int b[2000],int aw,int bw)
{
	for(int i=1;i<=n-m;i++)
	{
	if(a[i]<b[i])	
	return aw;
	if(a[i]>b[i])
	return bw;	
	}
	return aw;
}
int main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin>>n>>m>>kw)
	{
	kl=0;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
	k[1]=p[i];
	dfs(i,1,k);	
	}
	int o=1;
	for(int i=2;i<=kl;i++)
	o=bijiao(ans[i],ans[o],i,o);
	for(int i=1;i<=n-m;i++)
	printf("%d ",ans[o][i]);	
	printf("\n");
	}
	}
