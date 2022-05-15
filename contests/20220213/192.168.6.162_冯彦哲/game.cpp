#include<bits/stdc++.h>
using namespace std;
int T,n,k,num[50],a[50],e[50];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	a[0]=1;
	for(int i=1;i<=40;num[i]=num[i-1]+a[i],i++) a[i]=a[i-1]*2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(k==1){
			printf("Yes\n0\n");
			continue;
		}
		if(k%2==0) printf("NO\n");
		else {
			int op=114514,po=114514,l=0,tot=0;
			for(int i=0;i<=40;i++){
				for(int j=i-1;j>=0;j--)
					if(abs(k-(num[i]-num[j]))==1&&(num[i]-num[j])<=n){
						op=i,po=j;
						break;
					}
				if(k==num[i]) {
					for(int j=1;j<=i;j++) printf("%d ",l+a[j]);
					printf("\n");
					break;
					continue;
				}
			}	
			if(op==114514) {
				printf("NO\n");
				continue;
			}else printf("YES\n%d\n",op+1);
			if(a[op]<k){
				for(int i=op;i>po;i--){
					e[++tot]=l+1;
					l+=a[i];
				}
				l++;
				l-=a[po];
				e[++tot]=l+1;
				for(int i=po-1;i>=0;i--){
					l+=a[i];
					e[++tot]=l;
				}
				for(int i=tot;i>=1;i--) printf("%d ",e[i]);
				printf("\n");
			}else {
				for(int i=op;i>po;i--){
					e[++tot]=l+1;
					l+=a[i];
				}
				l-=a[po];
				e[++tot]=l+1;
				for(int i=po-1;i>=0;i--){
					e[++tot]=l+1;
					l+=a[i];
				}
				for(int i=tot;i>=1;i--) printf("%d ",e[i]);
				printf("\n");
			}
			
		}
	}
}
