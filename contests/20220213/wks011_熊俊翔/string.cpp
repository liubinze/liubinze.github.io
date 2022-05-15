#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,l,r;char s[500005],ch[5];
struct fwktr{
	int c[N];
	void add(int x,int y){for(;x<=n;x+=x&-x)c[x]+=y;}
	int sum(int x){int res=0;for(;x;x-=x&-x)res+=c[x];return res;}
}C;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;++i){
		scanf("%d%d%s",&l,&r,ch);
		if(l>n-C.sum(500001))continue;
		r=min(r,n-C.sum(500001));
		for(int i=l;i<=n;++i){
			if(i-C.sum(i-1)==l&&s[i]){
				l=i;
				break;
			}
		}
		for(int i=r;i<=n;++i){
			if(i-C.sum(i-1)==r&&s[i	]){
				r=i;break;
			}
		}
		for(int i=l;i<=r;++i)if(s[i]==ch[0])s[i]=0,C.add(i,1);
	}
	for(int i=1;i<=n;++i)if(s[i])printf("%c",s[i]);
	return 0;
}
