#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10005],g[10005],ans,gg;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
signed main(){
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		while(a[i]>m){
			int f=a[i]/m;
			a[i]%=m;
			a[i]+=f;
		}
		g[i]=gcd(a[i],m);
		int u=m/g[i];
		ans+=(0+(u-1)*g[i])*u/2;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			gg=(g[i]*g[j])/gcd(g[i],g[j]);
			while(gg>m){
			int f=gg/m;
			gg%=m;
			gg+=f;
			}
			int u=m/gg;
			ans-=(0+(u-1)*gg)*u/2;
		} 
	}
//	sort(g+1,g+1+n);
//	for(int i=1;i<=n;i++){
//		if(mark[i])continue;
//		int u=m/g[i];
//		ans+=(0+(u-1)*g[i])*u/2;
//		cout<<(0+(u-1)*g[i])*u/2<<" ";
//		for(int j=i+1;j<=n;j++){
//			if(g[j]%g[i]==0)mark[j]=1;
//		}
//	}
	printf("%lld",ans);
	return 0;
}

