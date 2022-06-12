#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],cntx[1001],cnty[1001];
pair<int,int>ma[1001];
int n,m,T,cnt;
bool flag=0;
char c[1001];
bool updown(int x) {
	int yy=ma[x].second;
	for(int i=ma[x].first-1; i>=1; i--) {
		if(a[i][yy]==1) {
			break;
		}
		if(a[i][yy]==0||a[i][yy]==3||a[i][yy]==4) {
			//cout<<a[i][yy]<<" "<<i<<" "<<yy<<endl;
			return 0;
		}
	}
	for(int i=ma[x].first+1; i<=n; i++) {
		if(a[i][yy]==1) {
			break;
		}
		if(a[i][yy]==0||a[i][yy]==3||a[i][yy]==4) {
			//cout<<a[i][yy]<<" "<<i<<" "<<yy<<endl;
			return 0;
		}
	}
	for(int i=ma[x].first-1; i>=1; i--) {
		if(a[i][yy]==1) {
			break;
		}
		//cout<<a[i][yy]<<" "<<i<<" "<<yy<<endl;
		if(a[i][yy]==2) {
			a[i][yy]=5;
		}
	}
	for(int i=ma[x].first+1; i<=n; i++) {
		if(a[i][yy]==1) {
			break;
		}
		//cout<<a[i][yy]<<" "<<i<<" "<<yy<<endl;
		if(a[i][yy]==2) {
			a[i][yy]=5;
		}
	}
//cout<<1<<endl;
	return 1;
}
bool rf(bool x) {
	int yy=ma[x].first;
	for(int i=ma[x].second-1; i>=1; i--) {
		//cout<<i<<endl;
		if(a[yy][i]==1) {
			break;
		}
		if(a[yy][i]==0||a[yy][i]==3||a[yy][i]==4) return 0;
	}
	for(int i=ma[x].second+1; i<=m; i++) {
		//cout<<i<<endl;
		if(a[yy][i]==1) {
			break;
		}
		if(a[yy][i]==0||a[yy][i]==3||a[yy][i]==4) {
			//cout<<a[yy][i]<<" "<<yy<<" "<<i<<endl;
			return 0;
		}
	}
	for(int i=ma[x].second-1; i>=1; i--) {
		if(a[yy][i]==1) {
			break;
		}
		if(a[yy][i]==2) {
			a[yy][i]=5;
		}
	}
	for(int i=ma[x].second+1; i<=m; i++) {
		if(a[yy][i]==1) {
			break;
		}
		if(a[yy][i]==2) {
			a[yy][i]=5;
		}
	}
	return 1;
}
bool check() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			//cout<<a[i][j]<<" ";
			if(a[i][j]==2) return 0;
		}
		//cout<<endl;
	}
	return 1;
}
void dfs(int x) {
	//cout<<cnt<<endl;
	//cout<<x<<endl;
	if(x>cnt) {
		if(check()) {
			flag=1;
			return;
		}
		return;
	}
	//cout<<updown(x)<<endl;
	if(updown(x)) {
		int nowx=cnty[ma[x].first];
		a[ma[x].first][ma[x].second]=4;
		cnty[ma[x].first]=0;
		//cout<<1<<" "<<x<<endl;
		dfs(x+1);
		//a[ma[x].first][ma[x].second]=0;
		cnty[ma[x].first]=nowx;
		int yy=ma[x].second;
		for(int i=ma[x].first-1; i>=1; i--) {
			if(a[i][yy]==1) {
				break;
			}
			if(a[i][yy]==5) {
				a[i][yy]=2;
			}
		}
		for(int i=ma[x].first+1; i<=n; i++) {
			if(a[i][yy]==1) {
				break;
			}
			if(a[i][yy]==5) {
				a[i][yy]=2;
			}
		}
		//cout<<nowx<<endl;
	}
	if(flag) return;
	//cout<<rf(x)<<endl;
	if(rf(x)) {
		int nowx=cntx[ma[x].second];
		a[ma[x].first][ma[x].second]=3;
		cntx[ma[x].second]=0;
		//cout<<x<<" "<<2<<endl;
		dfs(x+1);
		int yy=ma[x].first;
		cntx[ma[x].second]=nowx;
		for(int i=ma[x].second-1; i>=1; i--) {
			if(a[yy][i]==1) {
				break;
			}
			if(a[yy][i]==5) {
				a[yy][i]=2;
			}
		}
		for(int i=ma[x].second+1; i<=m; i++) {
			if(a[yy][i]==1) {
				break;
			}
			if(a[yy][i]==5) {
				a[yy][i]=2;
			}
		}
		//a[ma[x].first][ma[x].second]=0;
	}
	if(flag) return;
}
int main() {
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		flag=0;
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=m; i++) {
			cnty[i]=0;
		}
		for(int i=1; i<=n; i++) {
			cntx[i]=0;
			scanf("%s",&c);
			for(int j=1; j<=m; j++) {
				if(c[j-1]=='.') a[i][j]=2;
				if(c[j-1]=='#') a[i][j]=1;
				if(c[j-1]=='S') a[i][j]=0,ma[++cnt]= {i,j};
			}
		}
		dfs(1);
		if(!flag) printf("No\n");
		else {
			printf("Yes\n");
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					if(a[i][j]==2) printf(".");
					if(a[i][j]==1) printf("#");
					if(a[i][j]==3) printf("-");
					if(a[i][j]==4) printf("|");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
