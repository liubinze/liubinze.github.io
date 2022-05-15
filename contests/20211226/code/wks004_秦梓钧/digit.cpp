#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int T;
ll f(ll x){
	if(x<10)return x;
	int tot=0;
	while(x){
		tot+=x%10;
		x/=10;
	}
	return f(tot);
}
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ll l,r,ans=0;
		scanf("%lld%lld",&l,&r);
		if(l+10ll>=r){
			for(ll i=l;i<=r;i++)ans+=f(i);
			printf("%lld\n",ans);
		}
		else{
		for(;;l++){
		if(f(l)==1)break;
		ans+=f(l);
		}
		for(;;r--){
		if(f(r)==9)break;
		ans+=f(r);
		}
		printf("%lld\n",45*(r-l+1)/9+ans);
	}
	}
	return 0;
}
