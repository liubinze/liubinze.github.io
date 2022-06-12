#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ans+=x;
	}
	if(ans%m==0)cout<<ans/m;
	else cout<<ans/m+1;
}
