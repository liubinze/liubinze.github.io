#include<bits/stdc++.h>
using namespace std;
const int SIZE=1<<20; 
char buf[SIZE],*p1,*p2; 
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++) 
void read(int &x){ 
    x=0; 
    char ch; 
    while(!isdigit(ch=gc)); 
    do{ 
       x=10*x+ch-'0'; 
    }while(isdigit(ch=gc)); 
}
int kuan[1000005],n,w,ans;
int a[1000005];
bool ck(int len){
	memset(kuan,0,sizeof kuan);
	for(int i=1;i<=n;i++){
		int bl=i/len;
		if(i%len!=0)bl++;
		if(bl!=1)kuan[bl]=max(kuan[bl-1]+a[i]+1,kuan[bl]);
		if(bl==1)kuan[bl]=max(kuan[bl-1]+a[i],kuan[bl]);
		if(kuan[bl]>w)return 0;
	}
	return 1;
}
int main(){
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n);
	read(w);
	for(int i=1;i<=n;i++)read(a[i]);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(ck(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
