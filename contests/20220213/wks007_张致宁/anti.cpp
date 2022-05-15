#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k;
int t;
unsigned long long qpow(unsigned long long a,unsigned long long b){
	unsigned long long ans=1;
	while(b){
		if(b&1)ans*=a;
		b>>=1;
		a*=a;
	}
	return ans;
}
unsigned long long func(unsigned long long n,unsigned long long) {
	unsigned long long x=n&-n;
	unsigned long long s=(n+x)|((n^(n+x))/x)>>2;
	if(s>=qpow(2,k))return 0;
	return s;
}
main(){
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<func(n,k)<<endl;
	}
	return 0;
}

