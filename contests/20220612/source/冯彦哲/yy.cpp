#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,op[105],maxn,ans;
bool val1[15],val2[15],g[30][30];
vector<int> r[15];
void dfs1(int x) {
	if(x==n) {
		maxn=max(maxn,ans);
		return ;
	}
	if(maxn>=ans+n-x) return ;
	for(int j=0;j<r[x+1].size();j++) {
		int v=r[x+1][j];
		if(!val2[v]) {
			val2[v]=1;
			ans++;
			dfs1(x+1);
			val2[v]=0;
			ans--;
		}
	}
	dfs1(x+1); 
}
void dfs(int x) {
	if(x==n) {
		for(int i=1;i<=n;i++) {
			r[i].clear();
			int l=i,r1=i+1;
			if(r1>n) r1=1;
			for(int j=1;j<=n;j++)
				if(g[j][op[l]]==0&&g[j][op[r1]]==0)
					r[i].push_back(j); 
		}
		dfs1(0);	 
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!val1[i]) {
			val1[i]=1;
			op[x+1]=i;
			dfs(x+1);
			val1[i]=0;
		} 
}
int main() {
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		memset(g,0,sizeof(g));
		maxn=0;
		int x,y;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;g[x][y]=1,i++) scanf("%d%d",&x,&y);
		dfs(0);
		printf("%d\n",n-maxn);
	}
}
