#include<bits/stdc++.h>
using namespace std;
long long T,l,r,dp[205];
long long g(long long x){
	long long num=0;
	while(x>0){
		num+=x%10;
		x/=10;
	}
	return num;
}
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		long long l1=l,r1=r;
		while(l1>=10) l1=g(l1);
		while(r1>=10) r1=g(r1);
		printf("%lld\n",(r-l+1-(9-l1+1)-r1)*5+(l1+9)*(9-l1+1)/2+(1+r1)*r1/2);
	}
}
