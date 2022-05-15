#include<bits/stdc++.h>
using namespace std;
long long  n,k,w[100000],o[10000],q[100000],ans,lk[1000];
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
long long func(long long n)
{
	long long x=n&(-n);
	return (n+x)|((n^(n+x))/x)>>2;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);	
	int t;
	cin>>t;
	while(t>0)
	{
	t--;
	ans=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
	q[i]=0,w[i]=0,lk[i]=0;
	long long x=(-n)&n,p,ew=x;
	for(int i=1;i<=k;i++)
	{
		if(n==0)
		{
			p=i;
			break;
		}
		long long u=n>>1;
		u*=2;
		w[i]=n^u;
		q[i]+=w[i];
		if(q[i]==2)
		{
			q[i]=0;
			q[i+1]++;
		}		
		n/=2;
	}
	for(int i=1;i<=p;i++)
	{
		long long u=x>>1;
		u*=2;
		o[i]=x^u;
		q[i]+=o[i];
		if(q[i]==2)
		{
			q[i]=0;
			q[i+1]++;
		}
		x/=2;		
	}
	long  long wq=0;
	for(int i=p;i>=1;i--)
	{wq*=2;
		wq+=w[i]^q[i];		
	}
	wq/=ew;
	wq=wq>>2;
	for(int i=1;i<=p;i++)
	{
		long long u=wq>>1;
		u*=2;
		lk[i]=wq^u;
		wq/=2;
	}	 	
	for(int i=p;i>=1;i--)
	{	
		ans*=2;
		ans+=lk[i]|q[i];	
	}
	printf("%lld\n",ans);
	}
}
