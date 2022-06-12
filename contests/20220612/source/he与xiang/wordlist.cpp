#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
using namespace std;
const long long SIZE=1<<20;
char buf[SIZE],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)
void read(long long &x){
	x=0;
	char ch;
	while(!isdigit(ch=gc));
	do {
		x=x*10+ch-'0';
	}while(isdigit(ch=gc));
}
long long n,l,r;
long long w,a[1000005];
bool check(long long h){
	long long ans=0;
	for(long long i=1;i<=(n-1)/h+1;i++){
		long long an=0;
		for(long long j=(i-1)*h+1;j<=i*h&&j<=n;j++)
			an=max(an,a[j]);
		ans+=an+1;
	}
	if(ans<=w+1) return 1;
	else return 0;
}
int main(){
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n);
	read(w);
	for(long long i=1;i<=n;i++) read(a[i]);
	r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)==1) r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
}
