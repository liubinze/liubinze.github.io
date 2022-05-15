#include<bits/stdc++.h>
using namespace std;
int h[5005],x[5005],a[5005],t[5005];
int n,ls,an;
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
    scanf("%d",&n);
    h[0]=10000;
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
    	for(int j=ls;j>=0;j--){
			if(h[j]>a[i]){
				t[i]=x[j];
				h[j+1]=a[i];
				x[j+1]=i;
				break;
			}	
		}
		if(h[ls+1]!=0) ls++;
	}
	printf("%d\n",ls);
	an=x[ls];
	while(an!=0){
		printf("%d ",a[an]);
		an=t[an];
	}
	return 0;
}
