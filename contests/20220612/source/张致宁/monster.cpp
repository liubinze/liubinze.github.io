#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char s[30][30];
int l[30],r[30];
main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d%d",&n,&m);
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='*')l[i]++,r[j]++;
		for(int i=1;i<=min(n,m);++i){
			if(l[i]>0&&r[i]>0){
				++ans;
				l[i]=r[i]=0;
				for(int j=1;j<=n;++j)l[j]--;
				for(int j=1;j<=m;++j)r[j]--;
			}
		}
		for(int i=1;i<=n;++i){
			if(l[i]>0){
				++ans;
				l[i]=r[i]=0;
				for(int j=1;j<=n;++j)l[j]--;
				for(int j=1;j<=m;++j)r[j]--;
			}
		}
		for(int i=1;i<=n;++i){
			if(r[i]>0){
				++ans;
				l[i]=r[i]=0;
				for(int j=1;j<=n;++j)l[j]--;
				for(int j=1;j<=m;++j)r[j]--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
