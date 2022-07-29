#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#include<algorithm>
struct f
{
	int n,id;
}e[1000001];
int main()
{
	freopen("poklon.in","r",stdin),freopen("poklon.out","w",stdout);
	int n,q,l,r,ans;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&e[i].n),e[i].id=i;
	while(q--)
	{
		scanf("%d%d",&l,&r),ans=0ll,std::sort(e+l-1,e+r,[](f a,f b){return a.n<b.n;});
		for(int i=l-1,j;i<r;i++)
		{
			for(j=i+1;e[i].n==e[j].n&&j<r;j++);
			if(j-i==2)
				ans++;
			i=j-1;
		}
		printf("%d\n",ans),std::sort(e+l-1,e+r,[](f a,f b){return a.id<b.id;});
	}
	return 0;
}
