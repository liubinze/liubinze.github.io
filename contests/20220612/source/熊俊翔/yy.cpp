#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N],b[N],M[N][N],vis[N],link[N],n,m,x,y,ans=0x3f3f3f3f,res,T,k;
vector<int>p[N];
int dfs(int x){
	for(int i:p[x]){
		if(vis[i]!=k&&(vis[i]=k)){
			if(!link[i]||dfs(link[i])){
				link[i]=x;return 1;
			}
		}
	}
	return 0;
}
main(){
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(M,0,sizeof(M));
		for(int i=1;i<=m;++i){
			scanf("%d%d",&x,&y);
			M[x][y]=1;
		}
		ans=0x3f3f3f3f;
		for(int i=0;i<n;++i)a[i]=i+1,b[i]=i+1;
		if(n<=5){
			do{
				do{
					res=0;
					for(int i=0;i<n;++i){
						res+=!!(M[a[i]][b[(i+1)%n]]||M[a[i]][b[i]]);
					}
					ans=min(ans,res);
				}while(next_permutation(b,b+n));
			}while(next_permutation(a,a+n));	
			printf("%d\n",ans);
		}
		else{
			do{
				memset(link,0,sizeof(link));
				for(int i=1;i<=n;++i){
					p[i].clear();
					if(M[i][b[i-1]])continue;
					for(int j=0;j<n;++j){
						if(j+1==i||(j+1)%n+1==i)continue;
						if(!M[i][b[j]]){
							p[i].push_back(b[j]+n);
						}
					}
				}
				res=0;
				for(int i=1;i<=n;++i){
					++k;
					res+=dfs(i);
				}
				ans=min(ans,n-res);
			}while(next_permutation(b,b+n));
			printf("%d\n",ans);
		}
	}
}
