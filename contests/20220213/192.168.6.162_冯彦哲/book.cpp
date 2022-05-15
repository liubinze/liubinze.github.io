#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],l=-1000000000,r=1000000000;
int main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(l<r){
		long long mid=(l+r)>>1;
		long long h=a[1],k=0;
		for(long long i=2;i<=n;i++){
			if(h<mid&&a[i]>mid&&h+a[i]<=mid) h+=a[i];
			else if(mid>=h) h=a[i],k++;
			else if(h>mid) h+=a[i];
		}
		if(h<=mid) k++;
		if(k>=m) r=mid;
		else l=mid+1;
	}
	printf("%lld",l);
}
