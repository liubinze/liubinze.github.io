#include<iostream>
#include<cstring>
using namespace std;
int n,m;
string s;
int a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		a[i]=int(s[i-1]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char c;
		scanf("%d%d %c",&x,&y,&c);
		for(int i=x;i<=y;i++)
			if(a[i]==int(c))
				a[i]=0;
		for(int i=n;i>=1;i--)
			if(a[i]==0)
			{
				for(int j=i+1;j<=n;j++)
					a[j-1]=a[j];
				n--;
			}
	}
	for(int i=1;i<=n;i++)
		printf("%c",char(a[i]));
}

