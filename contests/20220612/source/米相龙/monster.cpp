#include<bits/stdc++.h>
using namespace std;
int T,n,m,ans=0x3f3f3f3f;
bool flag=0;
char c[33];
int a[33][33];
int cntx[33],cnty[33],cnttx[33],cntty[33];
bool check(){
	for(int i=1;i<=n;i++){
		if(cntx[i]){
			//printf("%d x\n",i);
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if(cnty[i]){
			//printf("%d y\n",i);
			return 0;
		}
	}
	return 1;
}
void dfs(int x,int y,int step){
	//cout<<x<<" "<<y<<" "<<step<<endl;
	for(int i=x;i<=n;i++){
		for(int j=y;j<=m;j++){
			if(cntx[i]&&cnty[j]){
				int nowx=cntx[i],nowy=cnty[j];
				cntx[i]=0;cnty[j]=0;
				dfs(i,j,step+1);
				cntx[i]=nowx;cnty[j]=nowy;
			}
		}
	}
	if(check()){
		ans=min(ans,step);
	}
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",&c);
			for(int j=1;j<=m;j++){
				if(c[j-1]=='*') cntx[i]++,cnty[j]++,cnttx[i]++,cntty[j]++;	
			}	
		}
		dfs(1,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
