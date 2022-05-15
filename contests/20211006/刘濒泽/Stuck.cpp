#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ss[3];
ll mark[1000001],lf,s[1000001];
vector<ll>v[1000001];
struct cow
{
	bool ps;
	ll x,y,_min;
}e[1000001];
struct eve
{
	ll id,jd,neum,faum;
}f[1000001];
void dfs(ll x)
{
	s[x]=1ll;
	for(ll i=0ll;i<v[x].size();i++)
		dfs(v[x][i]),s[x]+=s[v[x][i]];
	return;
}
int main()
{
	freopen("Stuck.in","r",stdin),freopen("Stuck.out","w",stdout);
	ll n,t;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%s%lld%lld",ss,&e[i].x,&e[i].y),e[i].ps=(ss[0]=='E'),e[i]._min=1e18;
	for(ll i=1ll;i<n;i++)
		for(ll j=0ll;j<i;j++)
			if(e[i].ps&&!e[j].ps&&e[i].x<=e[j].x&&e[i].y>=e[j].y)
				if(e[j].x-e[i].x<e[i].y-e[j].y)
					f[lf++]={i,j,e[j].x-e[i].x,e[i].y-e[j].y};
				else if(e[j].x-e[i].x>e[i].y-e[j].y)
					f[lf++]={j,i,e[i].y-e[j].y,e[j].x-e[i].x};
				else
					continue;
			else if(e[j].ps&&!e[i].ps&&e[j].x<=e[i].x&&e[j].y>=e[i].y)
				if(e[i].x-e[j].x<e[j].y-e[i].y)
					f[lf++]={j,i,e[i].x-e[j].x,e[j].y-e[i].y};
				else if(e[i].x-e[j].x>e[j].y-e[i].y)
					f[lf++]={i,j,e[j].y-e[i].y,e[i].x-e[j].x};
				else
					continue;
			else
				continue;
	sort(f,f+lf,[](eve a,eve b){return a.neum<b.neum;});
	for(ll i=0ll;i<lf;i++)
		if(e[f[i].id]._min>=f[i].neum&&!mark[f[i].jd])
			e[f[i].jd]._min=f[i].faum,mark[f[i].jd]=f[i].id+1ll,v[f[i].id].push_back(f[i].jd);
	for(ll i=0ll;i<n;i++)
		if(!mark[i])
			dfs(i);
	for(ll i=0ll;i<n;i++)
		printf("%lld\n",s[i]-1ll);
	return 0;
}
