#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int t,k;
ull n;
ull f(ull n){
	ull x=n&-n;
	return (n+x)|((n^(n+x))/x)>>2;
}
int main(){
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%llu%d",&n,&k);
		printf("%llu\n",f(n));
	}
	return 0;
}
