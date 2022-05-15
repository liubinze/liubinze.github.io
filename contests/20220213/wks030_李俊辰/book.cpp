#include<bits/stdc++.h>
using namespace std;
long long n,m,min_,kl=0,a[100000],val[100000];
bool xuan[100000];
void dfs(long long now,long long u,long long max_)
{
	if(u==0||now==n+1)
	{	
	if(kl>=m)
	{
		cout<<max_<<endl;
	min_=min(min_,max_);		
	}
	return;
	}
	for(long long i=1;i<=m;i++)
	{
		int k=kl,w=0;
		if(xuan[i]==false)
		{
		w=1;
		kl++;			
		}
		xuan[i]=true;
		a[i]+=val[now];
		int q=max_;
		max_=max(max_,a[i]);
		dfs(now+1,1,max_);
		dfs(now+1,0,max_);
		max_=q;
		a[i]-=val[now];
		if(w==1)
		{
			kl--;
			xuan[i]=false;			
		}

	}
}
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);		
	min_=1e9*10;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&val[i]);
	dfs(1,1,-1e11);
	cout<<min_;
}
