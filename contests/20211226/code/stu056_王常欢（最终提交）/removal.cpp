#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+10;
int n,m,k,a[N];
int main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	for(;scanf("%d%d%d",&n,&m,&k)==3;){
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		int k=n-m,idx=0;
		for(;k--;){
			int x=idx+1,d=x+m;
			for(int i=x+1;i<=d;i++){
				if(a[i]<a[x]){
					x=i;
				}
			}
			printf("%d ",a[x]);
			m-=x-idx-1;
			idx=x;
		}puts("");
	}
	return 0;
}
