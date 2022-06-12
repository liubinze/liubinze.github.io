#include<bits/stdc++.h>
using namespace std;
int T,n,m,h[26],Max,ans;
char s[26][26];
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=1e9;
		memset(h,0,sizeof(h));
		scanf("%d%d",&n,&m);
		Max=(1<<n)-1;
		for(int a=1;a<=n;a++) scanf("%s",s[a]+1);
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++)
			{
			    h[a]<<=1;
				if(s[a][b]=='*') h[a]^=1;
			}
		}
		for(int a=0;a<=Max;a++)
		{
			int tot1=0,tot2=0,x=0;
			for(int b=1,c=1;b<=n;b++,c<<=1)
			{
				if((a&c)==0)  x|=h[b];
				else tot1++;
			}
			for(int b=1,c=1;b<=m;b++,c<<=1)
			{
				if((x&c)!=0) tot2++;
			}
			ans=min(ans,max(tot1,tot2));
		}
		printf("%d\n",ans);
	}
}
