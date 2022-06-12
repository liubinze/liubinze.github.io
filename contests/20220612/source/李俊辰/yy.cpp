#include<bits/stdc++.h>
using namespace std;
bool used[100001];
int n,m,kk[20][20],ans=1e9;
void find(int x,int a[20])
{
	if(x==n*2+1)
	{	
	int je=n;
	for(int i=3;i<=n*2;i+=2)
	{
		if(kk[a[i]][a[i+1]]==true||kk[a[i-1]][a[i]]==true)
		{
			je--;
		}
	}	
	if(kk[a[1]][a[n*2]]==true||kk[a[1]][a[2]]==true)
	je--;
	ans=min(ans,n-je);	
	return;
	}
	if(x<=n)
	{
		for(int i=1;i<=n*2;i+=2)
		if(used[i]==false)
		{
			used[i]=true;
			a[i]=x;
			find(x+1,a);
			a[i]=0;
			used[i]=false;
		}
	}
	else
	{
		for(int i=2;i<=n*2;i+=2)
		if(used[i]==false)
		{
			used[i]=true;
			a[i]=x;
			find(x+1,a);
			a[i]=0;
			used[i]=false;
		}		
	}
}
int an[20];
int main(){
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);	
	int t;
	cin>>t;
	while(t>0)
	{
		t--;
		scanf("%d%d",&n,&m);
		ans=1e9;
		memset(kk,0,sizeof kk);
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			kk[a][b+n]=true;
			kk[b+n][a]=true;
		}
		find(1,an);
		printf("%d\n",ans);
	}
}
