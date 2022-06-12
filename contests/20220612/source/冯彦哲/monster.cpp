#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,ans,minn;
char s[30][30];
vector<int> r[30];
bool val[30],val1[30];
void dfs(int x) {
	if(x==n) {
		int num=0,ans=0;
		memset(val1,0,sizeof(val1));
		for(int i=1;i<=n;i++)
			if(!val[i]) {
				for(int j=0;j<r[i].size();j++)
					if(!val1[r[i][j]]) {
						num++;
						val1[r[i][j]]=1;
					}
			} else ans++;
		if(ans>=num) minn=min(ans,minn);
		return ;
	}
	dfs(x+1);
	val[x+1]=1;
	dfs(x+1);
	val[x+1]=0;
}
int main() {
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);	
	scanf("%d",&T);
	while(T--) {
		minn=0x3f3f3f3f;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("\n%s",s[i]+1);
		for(int i=1;i<=n;i++) {
			r[i].clear();
			for(int j=1;j<=m;j++)
				if(s[i][j]=='*') r[i].push_back(j);
		}
		dfs(0);
		printf("%d\n",minn);
	}
}
