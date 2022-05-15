#include<bits/stdc++.h>
#define ll long long
#define r register
using namespace std;

ll qz[1000005],l,rr;
inline ll f(ll n)
{
	r ll rt=0;
	while(n!=0) rt+=n%10,n/=10;
	return rt;
}
inline ll zf(ll n)
{
	if(n<10) return n;
	return zf(f(n));
}
long long ans[19];
signed main(signed argc,char **argv)
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	ans[1]=45,ans[2]=495,ans[3]=4995,ans[4]=49995,ans[5]=499995,ans[6]=4999995,ans[7]=49999995,ans[8]=499999995,ans[9]=4999999995,ans[10]=49999999995,ans[11]=499999999995,ans[12]=4999999999995,ans[13]=49999999999995,ans[14]=499999999999995,ans[15]=4999999999999995,ans[16]=49999999999999995,ans[17]=499999999999999995,ans[18]=4999999999999999995;
	for(r ll i=1;i<=1000000;++i)
	{
		qz[i]=qz[i-1]+zf(i);
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&l,&rr);
		if(l==1)
        {
            if(zf(rr)==1)
            {
                r int wei=0;
                while(rr!=0)
                {
                    ++wei;
                    rr/=10;
                }
                printf("%lld\n",ans[wei]+1);
            }
        }
		if(rr<=1000000) printf("%lld\n",qz[rr]-qz[l-1]);
		else
		{
				r ll ansz=0;
				for(r ll i=1;i<=rr;++i)
				{
					ansz+=zf(i);
				}
				printf("%lld\n",ansz);
		}
	}
	exit(0);
}

