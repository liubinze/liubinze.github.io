#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e4;
int tot,p[10005];
bool prime[10005];
int p1[10005],r[10005];
ll ans;
void dfs(int cnt,int rmax,int d,int now,int n1){
	if(now==cnt){
	ans=ans+(n1/d)*rmax;
	return;
	}
	now++;
	int c=1;
	for(int i=0;i<=r[now];i++){
		dfs(cnt,max(rmax,i),d*c,now,n1);
		c=c*p1[now];
	}
}
int main(){
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	for(int i=2;i<=N;i++){
		if(!prime[i])p[++tot]=i;
		for(int j=1;j<=tot&&1ll*i*p[j]<=N;j++){
			prime[i*p[j]]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		int n,n1,cnt=0;
		scanf("%d",&n);
		n1=n;
		for(int i=1;i<=tot&&p[i]*p[i]<=n;i++){
			if(n%p[i]==0){
				p1[++cnt]=p[i];
				r[cnt]=0;
				while(n%p[i]==0){
					n/=p[i];
					r[cnt]++;
				}
			}
		}
		if(n!=1)p1[++cnt]=n,r[cnt]=1;
		dfs(cnt,0,1,0,n1);
		printf("%lld\n",ans);
	}
	return 0;
}

