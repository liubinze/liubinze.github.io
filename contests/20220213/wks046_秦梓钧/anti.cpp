#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
ull func(ull n,ull k){
	if(k==64ull){
		ull x=(n)&(-n);
		ull m=(n+x)|((n^(n+x))/x)>>2ull;
		return m;
	}
	ull x=n&(-n);
	ull mod=1ull<<k;
	x%=mod;
	ull sum=(n+x)%mod;
	ull m=(sum)|((n^(sum))/x)>>2ull;
	m%=mod;
	return m;
}
int main(){
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ull n,k;
		cin>>n>>k;
		cout<<func(n,k)<<endl;
	}
	return 0;
}
