#include<bits/stdc++.h>
using namespace std;
long long t,l,r,ans;
int dfs(long long x){
    if(x<10) return x;
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return dfs(sum);
}
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&l,&r);
		for(int i=l;i<=r;i++){
			ans+=dfs(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
