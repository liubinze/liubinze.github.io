#include<bits/stdc++.h>
using namespace std;
int g[100005][15],s[100005],n,m,k,t;
main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);	
	for(;scanf("%d%d%d",&n,&m,&k)==3;){
		memset(g,0,sizeof(g));t=0;
		for(int i=1;i<=n;++i)scanf("%d",s+i);
		for(int i=n;i;--i){
			for(int j=1;j<=k;++j){
				if(s[i]==j)g[i][j]=i;
				else g[i][j]=g[i+1][j];
			}
		}
		for(int i=1;i<=n&&t<n-m;++i){
			for(int j=1;j<=k;++j){
				if(g[i][j]&&n-g[i][j]+1>=n-t-m){
					printf("%d ",j);
					i=g[i][j];++t;
					break;
				}
			}
		}
		puts("");
	}
}
