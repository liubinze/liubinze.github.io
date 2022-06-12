#include<bits/stdc++.h>
using namespace std;
int n,m;
bool c[25][55];
int ans;
bool use[55];
int l[55];
void dfs(int now){
	if(now==2*n+1){
		l[0]=l[2*n];
		int x=0;
		for(int i=1;i<=2*n;i+=2){
			if(c[l[i]][l[i-1]]||c[l[i]][l[i+1]])x++;
		}
		ans=min(ans,x);
	}
	if(now%2==0){
		for(int i=n+1;i<=n+n;i++){
			if(use[i])continue;
			use[i]=1;
			l[now]=i;
			dfs(now+1);
			use[i]=0;
			l[now]=0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(use[i])continue;
			use[i]=1;
			l[now]=i;
			dfs(now+1);
			use[i]=0;
			l[now]=0;
		}
	}
}
int main(){
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof c);
		scanf("%d%d",&n,&m);
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			c[x][y+n]=1;
		}
		ans=1e9;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
