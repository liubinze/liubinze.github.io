#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans;
bool bl[30],bb[30];
char c[30][30];
void dfs(int d,int cnt){
	if(ans<=cnt) return;
	if(d==n){
		int an=0;
		for(int j=0;j<m;j++) bb[j]=0;
		for(int i=0;i<n;i++){
			if(bl[i]==1) continue;
			for(int j=0;j<m;j++){
				if(bb[j]==1) continue;
				if(c[i][j]=='*') an++,bb[j]=1;
			}
		}
		ans=min(ans,max(cnt,an));
		return;
	}
	bl[d]=0;
	dfs(d+1,cnt);
	bl[d]=1;
	dfs(d+1,cnt+1);
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=1e9;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",&c[i]);
		dfs(0,0);
		printf("%d\n",ans);
	}
}
