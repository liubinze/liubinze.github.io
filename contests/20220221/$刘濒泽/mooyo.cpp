#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[101][11][1001];
ll n,k,s,e[101][11][1001],dx[5]={-1ll,0ll,1ll,0ll},dy[5]={0ll,-1ll,0ll,1ll};
pair<ll,ll>w;
queue<pair<ll,ll>>q;
int main()
{
	freopen("mooyo.in","r",stdin),freopen("mooyo.out","w",stdout);
	bool f;
	ll t,tt;
	scanf("%lld%lld",&n,&k);
	for(ll i=n-1ll;~i;i--)
		for(ll j=0ll;j<10ll;j++)
			scanf("%1lld",&e[i][j][0]);
	for(;;s++)
	{
		f=1;
		for(ll i=0ll;i<n;i++)
			for(ll j=0ll;j<10ll;j++)
				if(e[i][j][s]&&!mark[i][j][s])
				{
					q.push(make_pair(i,j)),t=0ll,tt=e[i][j][s];
					while(!q.empty())
					{
						w=q.front(),q.pop(),mark[w.first][w.second][s]=1,t++;
						for(ll k=0ll;k<4ll;k++)
							if(w.first+dx[k]>=0ll&&w.first+dx[k]<n&&w.second+dy[k]>=0ll&&w.second+dy[k]<10ll&&e[w.first+dx[k]][w.second+dy[k]][s]==tt&&!mark[w.first+dx[k]][w.second+dy[k]][s])
								q.push(make_pair(w.first+dx[k],w.second+dy[k]));
					}
					if(t<k)
						continue;
					q.push(make_pair(i,j)),f=0;
					while(!q.empty())
					{
						w=q.front(),q.pop(),e[w.first][w.second][s]=0ll;
						for(ll k=0ll;k<4ll;k++)
							if(w.first+dx[k]>=0ll&&w.first+dx[k]<n&&w.second+dy[k]>=0ll&&w.second+dy[k]<10ll&&e[w.first+dx[k]][w.second+dy[k]][s]==tt)
								q.push(make_pair(w.first+dx[k],w.second+dy[k]));
					}
				}
		if(f)
			break;
		for(ll j=0ll;j<10ll;j++)
		{
			t=0ll;
			for(ll i=0ll;i<n;i++)
				if(e[i][j][s])
					e[t++][j][s+1]=e[i][j][s];
		}
	}
	for(ll i=n-1ll;~i;i--,puts(""))
		for(ll j=0ll;j<10ll;j++)
			printf("%1lld",e[i][j][s]);
	return 0;
}
