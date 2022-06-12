//Neng Er Fen Ma? Bu Neng Ba, Hen Lan De La. 
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],n,w,res,ans;
struct segtr{
	int t[N*4];
	void pushup(int o){t[o]=max(t[o<<1],t[o<<1|1]);}
	void build(int l,int r,int o){
		if(l==r){t[o]=a[l];return;}
		int mid=l+r>>1;
		build(l,mid,o<<1);
		build(mid+1,r,o<<1|1);
		pushup(o);
	}
	int query(int ql,int qr,int l,int r,int o){
		if(ql<=l&&r<=qr){return t[o];}
		int mid=l+r>>1,ret=-0x3f3f3f3f;
		if(ql<=mid)ret=max(ret,query(ql,qr,l,mid,o<<1));
		if(qr>mid )ret=max(ret,query(ql,qr,mid+1,r,o<<1|1));
		return ret;
	}
}T;
const int SIZE = 1 << 20; 
char buf[SIZE], *p1, *p2; 
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++) 
void read(int &x) { 
    x = 0; 
    char ch; 
    while(!isdigit(ch = gc)); 
    do { 
       x = x*10 + ch - '0'; 
    }while(isdigit(ch = gc)); 
} 
int main(){
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n);read(w);
	for(int i=1;i<=n;++i)read(a[i]);
	T.build(1,n,1);
	for(int len=1;len<=n;++len){
		res=0; 
		for(int i=1,j=i+len-1;i<=n;i+=len,j+=len){
			j=min(j,n);
			res+=T.query(i,j,1,n,1);
			if(j!=n)++res;
			if(res>w)break;
		}
		if(res<=w){
			printf("%d",len);
			return 0;
		}
	}
	return 0;
}
