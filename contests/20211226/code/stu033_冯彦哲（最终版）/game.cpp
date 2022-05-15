#include<bits/stdc++.h>
using namespace std;
int T,n,m,num,x,y,u,v,l[35],flag;
char a[35][35];
bool g[35];
struct dog{int x,y;}val[35];
void dfs(int o,int i){
	if(flag) return ;
	if(o==num+1){
		if(val[i].x==u){
			if(l[num]==2&&val[i].y>v) return ;
			if(l[num]==4&&val[i].y<v) return ;
			printf("YES\n");flag=1;
			for(int k=1;k<=num;k++){
				if(l[k]==1) printf("U");
				else if(l[k]==2) printf("R");
				else if(l[k]==3) printf("D");
				else printf("L");
			}
			if(val[i].y<v) printf("R");
			else printf("L"); 
			printf("\n");
		}else if(val[i].y==v){
			if(l[num]==1&&val[i].x<u) return ;
			if(l[num]==3&&val[i].x>u) return ;
			printf("YES\n");flag=1;
			for(int k=1;k<=num;k++){
				if(l[k]==1) printf("U");
				else if(l[k]==2) printf("R");
				else if(l[k]==3) printf("D");
				else printf("L");
			}
			if(val[i].x>u) printf("U");
			else printf("D");	
			printf("\n"); 
		}
		return ;
	}
	for(int k=1;k<=num;k++) {
		if(!g[k]){
			if(val[k].x==val[i].x){
				if(l[o-1]==2&&val[i].y>val[k].y) continue;
				if(l[o-1]==4&&val[i].y<val[k].y) continue;
				if(val[i].y>val[k].y){
					l[o]=4,g[k]=1;
					dfs(o+1,k);
					l[o]=0,g[k]=0;
				}else {
					l[o]=2,g[k]=1;
					dfs(o+1,k);
					l[o]=0,g[k]=0;
				}	
			}else if(val[k].y==val[i].y){
				if(l[o-1]==1&&val[i].x<val[k].x) continue;
				if(l[o-1]==3&&val[i].x>val[k].x) continue;
				if(val[i].x>val[k].x){
					l[o]=1,g[k]=1;
					dfs(o+1,k);
					l[o]=0,g[k]=0;
				}else {
					l[o]=3,g[k]=1;
					dfs(o+1,k);
					l[o]=0,g[k]=0;
				}
			}
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=0,num=0;
		scanf("\n%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("\n");
			for(int j=1;j<=m;j++){
				scanf("%c",&a[i][j]);
				if(a[i][j]=='.') val[++num]=dog{i,j};
				if(a[i][j]=='S') x=i,y=j;
				if(a[i][j]=='T') u=i,v=j;
			} 
		}
		val[0]=dog{x,y};
		dfs(1,0);
		if(flag==0) printf("NO\n");
	}
}
