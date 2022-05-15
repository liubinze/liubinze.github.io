#include<bits/stdc++.h>
#define maxn 200002
using namespace std;
int n,m,xx,yy;
char zz;
string a;
struct tree{
	struct node{
		int cnt;
		char k;
	}tr[maxn<<2];
	void downcnt(int p){
		tr[p<<1].cnt=tr[p].cnt;
		tr[p<<1|1].cnt=tr[p].cnt;
	}
	void upcnt(int p){
		tr[p].cnt=tr[p<<1].cnt+tr[p<<1|1].cnt;
		tr[p<<1].cnt=0;tr[p<<1|1].cnt=0;
	}
	void build(int x,int y,int p){
		 if(x==y){
		 	tr[p].k=a[x-1];
		 	tr[p].cnt=0;
			 return;
		 }
		 int mid=(x+y)>>1;
		 build(x,mid,p<<1);
		 build(mid+1,y,p<<1|1);
	}
	void del(int l,int r,char kk,int x,int y,int p){
		//cout<<x<<" "<<y<<endl;
		if(x==y&&tr[p].k==kk){
			tr[p].k='#';
			tr[p].cnt++;
			//cout<<"#"<<endl;
			return;
		}
		if(x==y) return;
		int mid=(x+y)>>1;
		if(x!=mid&&y!=mid) downcnt(p);
		//cout<<tr[p<<1].cnt<<"cnt"<<tr[p<<1|1].cnt<<endl;
		if(l<=mid-tr[p].cnt) {
			
			del(l,r,kk,x,mid,p<<1);
		}
		if(r>=mid-tr[p].cnt) {
			del(l,r,kk,mid+1,y,p<<1|1); 
		}	
		upcnt(p);
	}
	void findt(int x,int y,int p){
		if(x==y&&tr[p].k!='#'){
			printf("%c",tr[p].k);
			return;
		}
		if(x==y) return;
		int mid=(x+y)>>1;
		findt(x,mid,p<<1);
		findt(mid+1,y,p<<1|1);
	}
}t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>a;
	t.build(1,n,1);
	for(int i=1;i<=m;i++){
		cin>>xx>>yy>>zz;
		t.del(xx,yy,zz,1,n,1);
		//cout<<endl<<endl;
	}
	t.findt(1,n,1);
	return 0;
}

