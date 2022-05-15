#include<bits/stdc++.h>
using namespace std;
int t,n,k,m,a[35],fl;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k),m=0;
		if(k==0)printf("YES\n0\n");
		else if(k%2==0)printf("NO\n");
		else{
			for(int i=k;i>0;i>>=1)a[++m]=i&1;
			a[0]=a[1],fl=1;
			for(int i=m,sum=n-k;i>=1;i--){
				if(a[i-1])sum+=(1<<m-i);
				else sum-=(1<<m-i);
				if(sum<0){fl=0;break;}
			}
			if(!fl)printf("NO\n");
			else{
				printf("YES\n%d\n",m);
				for(int i=m,sum=k;i>=1;i--){
					if(a[i-1])sum-=(1<<m-i),printf("%d ",sum+1);
					else printf("%d ",sum+1),sum+=(1<<m-i);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
