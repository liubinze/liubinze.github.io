#include<bits/stdc++.h>
using namespace std;
const int SZ=1<<20;
char buf[SZ],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++)
void read(long long &x){
	x=0ll;
	char ch;
	while(isdigit(ch=gc));
	do{
		x=x*10+ch-48;
	}while(isdigit(ch=gc));
}
void read(int &x){
	x=0;
	char ch;
	while(isdigit(ch=gc));
	do{
		x=x*10+ch-48;
	}while(isdigit(ch=gc));
}
int n;
long long a[1000005],ans,w,now;
main(){
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n),read(w);
	for(int i=1;i<=n;++i)read(a[i]);
	cout<<n;
	return 0;
}
