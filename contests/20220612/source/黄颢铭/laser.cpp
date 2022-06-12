#include<bits/stdc++.h>
using namespace std;
int  a[205][205];int n,m;

bool re=true,rer=true;
struct node{
	int x,y;
}e[2005];int tot=0;
char aaa[2005];
int res=0,ans=0;
void dfs(int u){
	if(re==false)return;
	if(u==tot+1){
		cout<<"No"<<endl;
		re=false;
		rer=false;
		return ;
	}
	int z,you;
	int x=e[u].x,y=e[u].y;
	int s1=0,s2=0;
    bool k1=true,k2=true;
    int da1=0,da2=0;
	for(int i=1;;i++){
		if(s1==1&&s2==1)break; 
		if(s1==0){
		    if(x-i==0){
		    	s1=1;
		    	z=x-i;
			}
			if(a[x-i][y]==1){
				s1=1;
				z=x-i+1;
			}
		    if(a[x-i][y]==99){
			    s1=-1;
			    break;
		    }
		    if(a[x-i][y]==2)da1++;
		    a[x-i][y]=3;
		}
		if(s2==0){ 
		    if(x+i==n){
		    	s2=1;
		    	you=x+i;
			}
			if(a[x-i][y]==1){
				s2=1;
				you=x+i-1;
			}
		    if(a[x-i][y]==99){
			    s2=-1;
			    break;
		    }
		    if(a[x+i][y]==2)da1++;
		    a[x+i][y]=3;
		}
	}
	if(s1==-1||s2==-1)k1=false;
	else {
		aaa[u]='|';
		res+=da1;
		if(res==ans){
			cout<<"YES";
			re=false;
			return;
		}
		dfs(u+1);
		for(int i=z;i<=you;i++){
			if(a[i][y]==3)a[i][y]=2;
		}
		res-=da1;
	}
	s1=s2=0;
	for(int i=1;;i++){ 
	
		if(s1==1&&s2==1)break; 
		if(s1==0){
		    if(y-i==0||a[x][y-i]==1)s1=1;
		    if(a[x][y-i]==99){
			    s1=-1;
			    break;
		    }
		    if(a[x][y-i]==2)da2++;
		    a[x][y-i]=3;
	}
		if(s2==0){ 
		    if(y+i==m||a[x][y+i]==1)s2=1;
		    if(a[x][y+i]==99){
			    s2=-1;
			    break;
		    }
		    if(a[x][y+i]==2)da2++;
		    a[x][y+i]=3;
		}
	}
	if(s1==-1||s2==-1)k2=false;
	else {
		aaa[u]='-';
		res+=da2;
		if(res==ans){
			cout<<"YES";
			re=false;
			return;
		}
		dfs(u+1);
	}
	if(k1==false&&k2==false){
		cout<<"No"<<endl;
		rer=false;
		re=false;
		return;
	}
}
char x;

int main(){
	//S=0  #=1 没打过=2 打过=3 
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		tot=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				if(x=='S'){
					a[i][j]=99;
					tot++;
					e[tot].x=i;
					e[tot].y=j;
				}
				if(x=='#')a[i][j]=1;
				if(x=='.')a[i][j]=2,ans++;
			}
		}
		dfs(1);
		tot=0;
		if(rer==false)continue;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==99){
					tot++;
					cout<<aaa[tot];
				}
				else {
					if(a[i][j]==1)cout<<'#';
					else cout<<'.';
			    }
			}
			cout<<endl;
		}
	}
}
