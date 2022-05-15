#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
ull n,k,T;
ull func(ull n){
	ull x=n&-n;
	return (n+x)|((n^(n+x))/x)>>2;
}
int main(){
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%llu",&T);
	for(int i=1;i<=T;++i){
		scanf("%llu%llu",&n,&k);
		ull t=n<<(64-k);
		ull a=func(t)>>(64-k);
		printf("%llu\n",a);
	}
	return 0;
}
