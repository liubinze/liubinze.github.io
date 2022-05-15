#include<bits/stdc++.h>
using namespace std;
long long T,n,prime[10000005],Minp[10000005],p[100005],r[100005],f[100005];
bool visit[10000005];
void Prime(){
	visit[1]=1;
	for(long long i=2;i<=10000000;i++){
		if(!visit[i]) prime[++prime[0]]=i,Minp[i]=i;
		for(long long j=1;j<=prime[0]&&i*prime[j]<=10000000;j++){
			visit[i*prime[j]]=1;
			Minp[i*prime[j]]=min(prime[j],Minp[i]);
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	Prime();
	scanf("%lld",&T);
	while(T--){
		long long ans=0;
		scanf("%lld",&n);
		long long t1=0,tot=0,w=n;
		while(w!=1){
			long long t=Minp[w],u=0;
			r[++t1]=0;
			p[t1]=t;
			while(w%t==0) w/=t,r[t1]++;
		}
		f[++tot]=1;
		for(long long l=1;l<=t1;l++){
			long long range=tot,pk=1;
			for(long long j=1;j<=r[l];j++){
				pk*=p[l];
				for(long long k=1;k<=range;k++){
					f[++tot]=pk*f[k];
				}
			}
		}
		for(long long i=1;i<=tot;i++){
			long long v=0,v1=0,w=f[i];
			while(w!=1){
				long long t=Minp[w],u=0;
				while(w%t==0) w/=t,u++;
				v=max(u,v);
			}
			ans+=v*n/f[i];
		}
		printf("%lld\n",ans);
	}
}
