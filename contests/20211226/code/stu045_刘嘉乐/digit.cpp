#include<bits/stdc++.h>
using namespace std;
int n;
long long l,r,f[205],ans;
int f1(long long l){
	int s=0;
	while(l)s+=l%10,l/=10;
	return s;
}
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=9;i++)f[i]=i;
	for(int i=10;i<=200;i++)f[i]=f[i/100+(i%100)/10+i%10];
	while(n--){
		scanf("%lld%lld",&l,&r),ans=0;
		for(long long i=l;i<=r;i++)ans+=f[f1(i)];
		printf("%lld\n",ans);
	}
	return 0;
}
