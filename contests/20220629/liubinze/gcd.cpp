#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int a[10001],s[10001],lf,f[10001],e[30000001];
inline int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	freopen("gcd.in","r",stdin),freopen("gcd.out","w",stdout);
	bool fl;
	int n,sa=0,g=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),sa+=a[i],g=gcd(g,a[i]);
	for(int i=0;i<n;i++)
		s[i]=(i?s[i-1]:0)+(a[i]/=g);
	sa/=g;
	for(int i=1,j;i*i<sa;i++)
		if(sa%i==0)
		{
			f[lf++]=i;
			if((j=sa/i)>i)
				f[lf++]=j;
		}
	sort(f,f+lf),printf("%d",sa*g);
	for(int k=2,i=lf-1,_;k<=n&&~i;k++,i--)
		for(i=min(i,int(upper_bound(f,f+lf,sa/k)-f-1));~i;i--)
		{
			fl=0;
			for(int j=0;j<f[i];j++)
				e[j]=0;
			for(int j=0;j<n;j++)
				e[s[j]%f[i]]++;
			for(int j=0;j<f[i]&&!fl;j++)
				if(e[j]>=k)
					fl=1,_=j;
			if(fl)
			{
				for(k--;k<e[_];k++)
					printf("\n%d",f[i]*g);
				break;
			}
		}
	return 0;
}
