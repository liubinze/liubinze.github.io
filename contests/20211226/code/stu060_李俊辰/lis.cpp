#include<bits/stdc++.h>
using namespace std;
bool used[5001];
int ans[2000][2000],max_,kl=0,k[2000];
int n,p[5000];
void dfs(int now,int l,int a[2000])
{
	for(int i=now+1;i<=n;i++)
	{
		if(p[i]>p[now])
		{
		a[l+1]=p[i];
		dfs(i,l+1,a);	
		}
	}
	if(l==max_)
	{
		kl++;
		for(int i=1;i<=l;i++)
		ans[kl][i]=a[i];		
	}
	if(l>max_)
	{
		kl=0;
		max_=l;
		kl++;
		for(int i=1;i<=l;i++)
		ans[kl][i]=a[i];
	}
	
}
int bijiao(int a[2000],int b[2000],int aw,int bw)
{
	for(int i=1;i<=max_;i++)
	{
	if(a[i]>b[i])	
	return aw;
	if(a[i]<b[i])
	return bw;	
	}
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
	k[1]=p[i];
	dfs(i,1,k);	
	}
	cout<<max_<<endl;
	int o=1;
	for(int i=2;i<=kl;i++)
	{
		o=bijiao(ans[i],ans[o],i,o);
	}
	for(int i=1;i<=max_;i++)
	printf("%d ",ans[o][i]);
	printf("\n");
}
