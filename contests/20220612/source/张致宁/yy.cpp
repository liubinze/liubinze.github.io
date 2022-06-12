#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,cnt;
vector<int>G[15];
bool Map[15][15];
main(){
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt=0;
		for(int i=1;i<=n;++i)G[i].clear();
		scanf("%d%d",&n,&m);
		memset(Map,0,sizeof Map);
		for(int i=1;i<=m;++i){
			scanf("%d%d",&x,&y);
			Map[x][y]=1;
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(!Map[i][j])G[i].push_back(j);
		for(int i=1;i<=n;++i)if(G[i].size()<2)++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}
