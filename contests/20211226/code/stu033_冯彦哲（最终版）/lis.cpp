#include<bits/stdc++.h>
using namespace std;
int a[5005],h[5005],dis[5005],l[5005],l1[5005],num,n,o;
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;h[i]=1,i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		int id=0,u=0;
		for(int j=1;j<i;j++){
			if(a[i]>a[j]&&(h[j]>u||(h[j]==u&&a[id]<a[j]))){
				id=j,u=h[j];
			}
		}
		h[i]=u+1;
		dis[i]=id;
	}
	for(int i=1;i<=n;i++){
		if(h[i]>o){
			int p=i,num1=0;
			while(p>0){
				l[++num1]=p;
				p=dis[p];
			}
			num=num1;
			o=h[i];
		}else if(h[i]==o){
			int p=i,num1=0;
			bool flag=0;
			while(p>0){
				l1[++num1]=p;
				p=dis[p];
			}
			while(num1>0){
				if(a[l[num1]]>a[l1[num1]]){
					break;
				}else if(a[l[num1]]<a[l1[num1]]){
					flag=1;
					break;
				}
				num1--;
			}
			if(flag==1){
				for(int j=1;j<=o;j++){
					l[j]=l1[j];
				}
			}
		}
	}
	printf("%d\n",o);
	while(num>0){
		printf("%d ",a[l[num]]);
		num--;
	}
}
