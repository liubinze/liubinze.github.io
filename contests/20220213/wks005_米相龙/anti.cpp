#include<bits/stdc++.h>
using namespace std;
unsigned long long nn,k,T;
inline unsigned long long func(unsigned long long n) {
	unsigned long long x=n&-n;
	return (n+x)|((n^(n+x))/x)>>2;
}
int main() {
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>nn>>k;
		cout<<func(nn)<<endl;
	}
	return 0;
}

