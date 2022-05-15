#include<bits/stdc++.h>
#define int long long
using namespace std;
/***************************************************************************/
#define gc ZZ==zz&&(zz=(ZZ=buf)+fread(buf,1,2000005,stdin),ZZ==zz)?EOF:*ZZ++
static char buf[2000005],*ZZ=buf,*zz=buf;
inline int read() {
	int x(0);
	char ch(gc);
	while(ch<'0'||ch>'9')ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc;
	return x;
}
/***************************************************************************/
int n,m,T,k,cnt,i,poww=1;
int a[40];
main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	T=read();
	while(T--){
		n=read();k=read();cnt=0;
		if(k==0) {
			printf("YES\n0\n");
		}
		else{
			i=1;poww=1;
			while(i<=k){
				a[++cnt]=i;
				poww<<=1;
				i+=poww;
			}
			if(i-poww!=k){
				printf("NO\n");
			}
			else{
				printf("YES\n%d\n",cnt);
				for(int j=1;j<=cnt;j++){
					printf("%d ",a[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

