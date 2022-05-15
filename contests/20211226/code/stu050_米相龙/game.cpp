#include<bits/stdc++.h>
using namespace std;
int t,n,ans_x,ans_y,m,cnt;
char a[33][33],b[33];
bool flag;
int fx[5]= {-1,1,0,0};
int fy[5]= {0,0,-1,1};
deque<char>ans;
void pr() {
	printf("YES\n");
	while(ans.size()) {
		printf("%c",ans.front());
		ans.pop_front();
	}
	printf("\n");
}
void dfs(int last,int w,int x,int y) {
	if(x>n||y>m||y<1||x<1) return;
	if(a[x][y]=='T'&&w==0) {
		pr();
		flag=1;
		return;
	}
	if(a[x][y]=='#') {
		if(last==0) {
			dfs(0,w,x-1,y);
		}
		if(last==1) {
			dfs(1,w,x+1,y);
		}
		if(last==2) {
			dfs(2,w,x,y-1);
		}
		if(last==3) {
			dfs(3,w,x,y+1);
		}
	} else {
		for(int i=0; i<4; i++) {
			int dx=x+fx[i];
			int dy=y+fy[i];
			a[dx][dy]='#';
			if(i==0)
				ans.push_back('U');
			if(i==1)
				ans.push_back('D');
			if(i==2)
				ans.push_back('L');
			if(i==3)
				ans.push_back('R');
			dfs(i,w-1,dx,dy);
			if(flag) return;
			a[dx][dy]='.';
			ans.pop_back();
		}
	}
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		flag=0;
		int xx,yy;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++) {
			scanf("%s",&b);
			for(int j=1; j<=m; j++) {
				a[i][j]=b[j-1];
				if(a[i][j]=='S') xx=i,yy=j;
				if(a[i][j]=='T')ans_x=i,ans_y=j,cnt++;
				if(a[i][j]=='.') cnt++;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<a[i][j];
//			}
//			printf("\n");
//		}
		dfs(0,cnt,xx,yy);
		if(!flag) printf("NO\n");
	}
	return 0;
}
