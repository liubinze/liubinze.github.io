#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
long long n,m,ans,i;
long long a[maxn];
bool flag=1;
int main() {
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=m/a[n]; flag; i++) {
		//cout<<i<<endl;
		ans=0;
		flag=0;
		for(long long j=n; j-i>=1; j-=i) {
			ans+=a[j]+1;
			//cout<<j<<endl;
		}
		if(ans>m&&ans-1>m) {
			flag=1;
		}
		//cout<<ans<<endl;
	}
	printf("%lld",i);
	return 0;
}

