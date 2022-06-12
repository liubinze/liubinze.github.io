#include<bits/stdc++.h>
using namespace std;
int n,m,t,a,b,ans;
bool bb[10][10],bl[2][10];
void dfs(int u,int y,int d,int an,int f){
	if(d==n-1){
		for(int i=1;i<=n;i++){
			if(bl[1][i]==0){
				if(bb[u][y]==0&&bb[u][i]==0) an++;
				if(bb[1][i]==0&&bb[1][f]==0) an++;
				ans=max(ans,an);
			}
		}
		return;
	}
	bl[0][u]=1;
	for(int i=1;i<=n;i++){
		if(bl[1][i]==1) continue;
		bl[1][i]=1;
		for(int j=2;j<=n;j++){
			if(bl[0][j]==1) continue;
			if(bb[u][y]==0&&bb[u][i]==0)
				dfs(j,i,d+1,an+1,f);
			else dfs(j,i,d+1,an,f);
		}
		bl[1][i]=0;
	}
	bl[0][u]=0;
}
int main(){
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				bb[i][j]=0;
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			bb[a][b]=1;
		}
		bl[0][1]=1;
		for(int i=1;i<=n;i++){
			bl[1][i]=1;
			for(int j=2;j<=n;j++){
				dfs(j,i,1,0,i);
			}
			bl[1][i]=0;
		}
		printf("%d\n",n-ans);
	}
}
