#include<bits/stdc++.h>
using namespace std;
int a[100100];
int n,m,k,x;
int main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin>>n>>m>>k){
		for(int i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		n=n-m;
		x=1;
		for(int i=1;i<=n;i++){
			int mins=15,sx=0;
			for(int j=x;j<=x+m;j++){
				if(a[j]<mins){
					mins=a[j];
					sx=j;
				}
			}
			m=m+x-sx;
			x=sx+1;
			printf("%d ",mins);
		}
		printf("\n");
	}
}
