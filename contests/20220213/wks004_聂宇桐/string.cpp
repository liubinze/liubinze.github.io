#include<bits/stdc++.h>
using namespace std;
int n,m,len;
char s[2000005],tp[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=n;
	scanf(" %s",&s);
	while(m--)
	{
		int l,r,ll=0;
		char c;
		scanf("%d%d %c",&l,&r,&c);
		if(r>len)r=len;
		if(l>len)continue;
		for(int i=1;i<=len;i++)
		{
			tp[i]=s[i];
			s[i]=' ';
		}
		for(int i=l;i<=r;i++)
		{
			if(tp[i]==c)
			{
				tp[i]=' ';
				len--;
			}
		}
		for(int j=1;j<=len;j++)
		{
			if(tp[j]!=' ')
			{
				s[++ll]=tp[j];
			}
		}
		for(int i=1;i<=ll;i++)
		{
			tp[i]=' ';
		}
	}
	for(int i=1;i<=len;i++)
	{
		if(s[i]!=' ')
		printf("%c",s[i]);
	}
}

