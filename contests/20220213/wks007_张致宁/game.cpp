#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,k,num;
int is(int x){
	int cnt=0;
	for(;x!=1;++cnt,x>>=1)if(x&1)return 0;
	return cnt;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans*=a;
		b>>=1;
		a*=a;
	}
	return ans;
}
main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(!k){
			cout<<"YES"<<endl<<0<<endl;
			continue;
		}
		if(is(k+1)){
			cout<<"YES"<<endl<<is(k-1)<<endl;
			for(int i=1;qpow(2,i)-1<=k;++i)cout<<qpow(2,i)-1<<' ';
			cout<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}
