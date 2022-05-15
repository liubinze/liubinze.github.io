#include<bits/stdc++.h>
using namespace std;
int n,m,c,t[100001];
bool cmp(int a,int b)
{
	return a<b;
}
int ans=1e9;
void dfs(int now,int last,int car,int num,int max_)
{
//	cout<<now<<" "<<last<<" "<<car<<" "<<num<<" "<<max_<<endl;
	if(car>m&&now!=n+1)
	return;
	if(max_>ans)
	return;
	if(now==n+1)
	{
	ans=min(max_,ans);		
	return;
	}
	if(last==-1)
	last=t[now];
	if(num==c)
	{
	dfs(now+1,-1,car+1,1,max(max_,t[now]-last));
	return;
	}
	dfs(now+1,-1,car+1,1,max(max_,t[now]-last));
	dfs(now+1,last,car,num+1,max(max_,t[now]-last));
	return;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	sort(t+1,t+1+n,cmp);
	dfs(1,-1,1,1,-1e9);
	cout<<ans;
}
