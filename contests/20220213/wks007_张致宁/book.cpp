#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],mx=LLONG_MIN;
main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],mx=max(mx,a[i]);
	cout<<mx;
	return 0;
}
