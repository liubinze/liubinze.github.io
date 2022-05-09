#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[103][103];
bool mark[103][103][11][33];
ll n,sn,link[103][103],dis[103][103][11][33],dx[5]={-1ll,0ll,1ll,0ll},dy[5]={0ll,-1ll,0ll,1ll};
struct poi
{
	ll x,y,k,s,di;
};
inline bool operator<(poi a,poi b)
{
	return a.di>b.di;
}
priority_queue<poi>q;
inline void dijsktra(ll sx,ll sy)
{
	ll t,m,p;
	poi z;
	for(ll i=0ll;i<101ll;i++)
		for(ll j=0ll;j<101ll;j++)
			for(ll k=0ll;k<11ll;k++)
				for(ll l=0ll;l<33ll;l++)
					dis[i][j][k][l]=1e18;
	dis[sx][sy][0][0]=0ll,q.push(poi{sx,sy,0ll,0ll,0ll});
	while(!q.empty())
	{
		z=q.top(),q.pop();
		if(mark[z.x][z.y][z.k][z.s])
			continue;
		mark[z.x][z.y][z.k][z.s]=1;
		for(ll i=0ll;i<4ll;i++)
			if(z.x+dx[i]>=0ll&&z.x+dx[i]<n&&z.y+dy[i]>=0ll&&z.y+dy[i]<n&&s[z.x+dx[i]][z.y+dy[i]]^'#'&&dis[z.x+dx[i]][z.y+dy[i]][t=z.k+int(s[z.x+dx[i]][z.y+dy[i]]-'1'==z.k)][m=z.s|(s[z.x+dx[i]][z.y+dy[i]]^'S'?0:1<<link[z.x+dx[i]][z.y+dy[i]])]>(p=z.di+1ll+(s[z.x+dx[i]][z.y+dy[i]]^'S'?0ll:ll((z.s|1<<link[z.x+dx[i]][z.y+dy[i]])!=z.s))))
				dis[z.x+dx[i]][z.y+dy[i]][t][m]=p,q.push(poi{z.x+dx[i],z.y+dy[i],t,m,p});
	}
	return;
}
int main()
{
	freopen("master.in","r",stdin),freopen("master.out","w",stdout);
	ll m,kx,ky,tx,ty,_min=1e18;
	scanf("%lld%lld",&n,&m);
	for(ll i=0ll;i<n;i++)
	{
		scanf("%s",s[i]);
		for(ll j=0ll;j<n;j++)
			if(s[i][j]=='S')
				link[i][j]=sn++;
			else if(s[i][j]=='K')
				kx=i,ky=j;
			else if(s[i][j]=='T')
				tx=i,ty=j;
	}
	dijsktra(kx,ky);
	for(ll i=0ll;i<1ll<<sn;i++)
		_min=min(_min,dis[tx][ty][m][i]);
	if(_min<1e18)
		printf("%lld",_min);
	else
		printf("impossible");
	return 0;
}
