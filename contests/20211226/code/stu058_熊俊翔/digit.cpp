#include<bits/stdc++.h>
#define int long long
#define m(x) (x%9==0?9:x%9)
using namespace std;
int t[25],q,l,r,d;
main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	for(int i=1;i<=20;++i)t[i]=t[i-1]+m(i);
    scanf("%lld",&q);
    for(int i=1;i<=q;++i){
    	scanf("%lld%lld",&l,&r);
    	d=(r-l)/9;
    	if(m(l)<m(r))printf("%lld\n",45ll*d+t[m(r)]-t[m(l)-1]);
    	else if(m(l)>m(r))printf("%lld\n",45ll*d+t[m(r)+9]-t[m(l)-1]);
    	else printf("%lld\n",t[m(l)]-t[m(l)-1]);
	}
}
