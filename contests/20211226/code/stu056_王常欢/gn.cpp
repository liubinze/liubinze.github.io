#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e7;
int KSM(int a,int b){
	int res=1;
	for(;b;){
		if(b&1)res*=a;
		a*=a,b>>=1;
	}return res;
}
int t,n,f[N],c[N],primes[N/10],mpr[N],idx,d,u;
bool st[N];
int ans;
void dfs(int p,int s,int k){
	if(k)ans+=f[p]*(n/p);
	if(s==1)return;
	int x=mpr[s],y=c[s];
	s/=KSM(x,y);
	dfs(p,s,0);
	for(int j=1;j<=y;j++){
		p/=x;
		dfs(p,s,1);
	}
}
int main(){
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	for(int i=2;i<=N;i++){
		if(!st[i]){
			primes[++idx]=i;
			f[i]=c[i]=1;
			mpr[i]=i;
		}
		for(int j=1;primes[j]<=N/i;j++){
			u=primes[j]*i;
			st[u]=1;
			mpr[u]=primes[j];
			if(i%primes[j]==0){
				c[u]=c[i]+1;
				d=KSM(primes[j],c[u]);
				f[u]=max(f[u/d],c[u]);
				break;
			}
			f[u]=f[i];
			c[u]=1;
		}
	}
	scanf("%d",&t);
	for(;t--;){
		scanf("%d",&n);
		ans=0;
		dfs(n,n,1);
		printf("%d\n",ans);
	}
	return 0;
}
