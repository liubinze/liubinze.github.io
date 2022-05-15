#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[1000005],f[10000005],fp[10000005],a[10000005],t,n,ans;
int qp(int x,int y){int res=1;for(;y;y>>=1)res*=y&1?x:1,x*=x;return res;}
int g(int x){
	int res=0;
	for(int i=1;i<=x/i;++i){
		if(x%i==0)res+=i*f[x/i];
		if(x%i==0&&i-x/i)res+=x/i*f[i];
	}
	return res;
}
main(){
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	for(int i=2;i<=10000000;++i){
		if(!a[i])p[++t]=fp[i]=i,f[i]=1;
		for(int j=1;j<=t&&i*p[j]<=10000000;++j){
			a[i*p[j]]=1;
			if(i%p[j])f[i*p[j]]=f[i];
			else{f[i*p[j]]=(i*p[j]%(qp(p[j],f[i]+1))==0?f[i]+1:f[i]);break;}
		}
	}
	scanf("%lld",&t);
	for(;t--;){
		scanf("%lld",&n);
		printf("%lld\n",g(n));
	}
}
