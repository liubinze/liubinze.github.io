#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1 << 20; 
char buf[SIZE], *p1, *p2; 
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++) 
void read(int &x) { 
    x = 0; 
    char ch; 
    while(!isdigit(ch = gc)); 
    do { 
       x = x*10 + ch - '0'; 
    }while(isdigit(ch = gc)); 
} 
int n,w,l,r;
int a[1000005],ans;
bool check(int x) {
	int num=0,k=0,maxn=0;
	for(int i=1;i<=n;i++) {
		num++;
		maxn=max(maxn,a[i]);
		if(num==x) k+=maxn+1,maxn=0,num=0;
	}
	if(num!=0) k+=maxn+1;
	if(k-1<=w) return 1;
	else return 0;
}
int main() {
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n);read(w);
	for(int i=1;i<=n;i++) read(a[i]);
	l=1,r=n;
	while(l<=r) {
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
}
