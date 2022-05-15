#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,t,a[201][201],b[201][201],c[201][201][5],d[201][201],e[201][201],dis[201][201][61][5],dx[5]={0ll,1ll,0ll,-1ll},dy[5]={1ll,0ll,-1ll,0ll},_min=0x3f3f3f3f3f3f3f3fll;
struct st//di:	ESWN
{//				0123
	ll x,y,ti,di,s;
}_now,_next;
queue<st>q;
int main()
{
	freopen("street.in","r",stdin),
	freopen("street.out","w",stdout);
	ll xe,ye;
	scanf("%lld%lld%lld%lld%lld",&n,&m,&t,&xe,&ye),xe--,ye--;
	for(ll i=0ll;i<n;i++)
		for(ll j=0ll;j<m;j++)
			scanf("%lld%lld%lld%lld",&a[i][j],&b[i][j],&d[i][j],&e[i][j]),c[i][j][0]=e[i][j],c[i][j][1]=d[i][j],c[i][j+1][2]=e[i][j],c[i+1][j][3]=d[i][j];
	memset(dis,0x3f,sizeof(dis)),q.push(st{0ll,0ll,0ll,3ll,0ll}),dis[0][0][0][3]=0ll;
	while(!q.empty())
	{
		_now=q.front(),q.pop(),_next=_now;
		_next.di=_now.di+1ll&3ll,_next.x=_now.x+dx[_next.di+2ll&3ll],_next.y=_now.y+dy[_next.di+2ll&3ll],_next.ti=(_now.ti+c[_now.x][_now.y][_next.di+2ll&3ll])%t;
		if(_next.x>=0ll&&_next.x<n&&_next.y>=0ll&&_next.y<m&&dis[_next.x][_next.y][_next.ti][_now.di]>_now.s+c[_now.x][_now.y][_next.di+2ll&3ll])
			dis[_next.x][_next.y][_next.ti][_next.di]=_now.s+c[_now.x][_now.y][_next.di+2ll&3ll],
			q.push(st{_next.x,_next.y,_next.ti,_next.di,dis[_next.x][_next.y][_next.ti][_next.di]});
		_next.di=_now.di&3ll,_next.x=_now.x+dx[_next.di+2ll&3ll],_next.y=_now.y+dy[_next.di+2ll&3ll],_next.ti=(_now.ti+(a[_now.x][_now.y]||b[_now.x][_now.y]?((_now.di&1ll)?(_now.ti<a[_now.x][_now.y]?a[_now.x][_now.y]-_now.ti:0ll):(_now.ti>=a[_now.x][_now.y]?t-_now.ti:0ll)):0ll)+c[_now.x][_now.y][_next.di+2ll&3ll])%t;
		if(_next.x>=0ll&&_next.x<n&&_next.y>=0ll&&_next.y<m&&dis[_next.x][_next.y][_next.ti][_now.di]>_now.s+10ll*(_next.ti-_now.ti)+c[_now.x][_now.y][_next.di+2ll&3ll])
			dis[_next.x][_next.y][_next.ti][_next.di]=_now.s+10ll*(_next.ti-_now.ti)+c[_now.x][_now.y][_next.di+2ll&3ll],
			q.push({_next.x,_next.y,_next.ti,_next.di,dis[_next.x][_next.y][_next.ti][_next.di]});
		_next.di=_now.di+3ll&3ll,_next.x=_now.x+dx[_next.di+2ll&3ll],_next.y=_now.y+dy[_next.di+2ll&3ll],_next.ti=(_now.ti+(a[_now.x][_now.y]||b[_now.x][_now.y]?((_now.di&1ll)?(_now.ti<a[_now.x][_now.y]?a[_now.x][_now.y]-_now.ti:0ll):(_now.ti>=a[_now.x][_now.y]?t-_now.ti:0ll)):0ll)+c[_now.x][_now.y][_next.di+2ll&3ll])%t;
		if(_next.x>=0ll&&_next.x<n&&_next.y>=0ll&&_next.y<m&&dis[_next.x][_next.y][_next.ti][_now.di]>_now.s+10ll*(_next.ti-_now.ti)+c[_now.x][_now.y][_next.di+2ll&3ll])
			dis[_next.x][_next.y][_next.ti][_next.di]=_now.s+10ll*(_next.ti-_now.ti)+c[_now.x][_now.y][_next.di+2ll&3ll],
			q.push({_next.x,_next.y,_next.ti,_next.di,dis[_next.x][_next.y][_next.ti][_next.di]});
	}
	for(ll i=0ll;i<t;i++)
		_min=min(_min,min(min(dis[xe][ye][i][0],dis[xe][ye][i][1]),min(dis[xe][ye][i][2],dis[xe][ye][i][3])));
	printf("%lld",_min);
	return 0;
}
