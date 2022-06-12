#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t;
int ans[5005],a,b;
struct A{
	int x,y;
}e[5005];
vector<int>west,east;
bitset<5005>bs[5005];
main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&e[i].x,&e[i].y);
		if(e[i].x==a)east.push_back(i);
		if(e[i].x==0)west.push_back(i);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&t);
		if(t==1)bs[x][y]=1;
		else bs[x][y]=bs[y][x]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(bs[i][j])bs[i]|=bs[j];
		}
	}
	for(int i:west){
		int v=e[i].y;
		for(int j:east){
			if(bs[i][j])++ans[v];
		}
	}
	for(int i:west)cout<<ans[e[i].y]<<endl;
	return 0;
}
