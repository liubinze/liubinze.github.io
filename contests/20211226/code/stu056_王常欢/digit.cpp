#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int t;
ll a,b,ans;
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&t);
	for(;t--;){
		ans=0;
		scanf("%lld%lld",&a,&b);
		int x=a%9;
		ans+=x==0?9:x;
		for(;a%9!=b%9;){
			a++;
			x=a%9;
			ans+=x==0?9:x;
		}
		ans+=(b-a)*5;
		printf("%lld\n",ans);
	}
	return 0;
}
