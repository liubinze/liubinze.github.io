#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005],b[5005],f[5005],xl[5005],yl[5005],ans;
bool check(int x,int y){
	xl[1]=x,yl[1]=y;
	for(int i=2;i<=f[x];i++)xl[i]=b[xl[i-1]],yl[i]=b[yl[i-1]];
	for(int i=f[x];i>=1;i--){
		if(a[xl[i]]>a[yl[i]])return 1;
		if(a[xl[i]]<a[yl[i]])return 0;
	}
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=1,k=0;
		for(int j=1;j<i;j++)if(a[j]<a[i]&&f[j]>=f[k]){
			if(f[j]>f[k])k=j;
			else if(check(j,k))k=j;
		}
		f[i]=f[k]+1,b[i]=k;
	}
	for(int i=1;i<=n;i++)if(f[i]>=f[ans]){
		if(f[i]>f[ans])ans=i;
		else if(check(i,ans))ans=i;
	}
	printf("%d\n",f[ans]),xl[1]=ans;
	for(int i=2;i<=f[ans];i++)xl[i]=b[xl[i-1]];
	for(int i=f[ans];i>=1;i--)printf("%d ",a[xl[i]]);
	return 0;
}
