#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[200005];
int n,m;
bool ck(int k){
	int can=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=arr[i];
		if(sum<=k){
			can++;
			sum=0;
		}
	}
	if(can>=m)return 1;
	else return 0;
}
signed main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
	int l=-1e9*n-1,r=1e9+1,mid,ans;
	while(l<=r){
		mid=(l+r)/2ll;
		if(ck(mid))r=mid-1,ans=mid;
		else l=mid+1ll;
	}
	printf("%lld",ans);
	return 0;
}
