#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char c[1000001],d[1000001],e[1000001];
string s;
map<string,string>m;
int main()
{
	freopen("preprocessor.in","r",stdin),freopen("preprocessor.out","w",stdout);
	ll n,lc,t;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
	{
		c[0]=getchar(),c[1]='\0';
		while(c[0]<' '||c[0]>'~')
			c[0]=getchar();
		scanf("%[^\n]",c+1),lc=strlen(c),d[t=0]='\0';
		if(c[0]=='#'&&c[1]=='d'&&c[2]=='e'&&c[3]=='f'&&c[4]=='i'&&c[5]=='n'&&c[6]=='e'&&c[7]==' ')
			sscanf(c+8,"%[_0-9A-Za-z]",d),m[s=d]=string(c+9+strlen(d));
		else if(c[0]=='#'&&c[1]=='u'&&c[2]=='n'&&c[3]=='d'&&c[4]=='e'&&c[5]=='f'&&c[6]==' ')
			sscanf(c+7,"%[_0-9A-Za-z]",d),m.erase(s=d);
		else
			while(t<lc)
			{
				sscanf(c+t,"%[^_0-9A-Za-z]",d),t+=strlen(d),printf("%s",d);
				if(t>=lc)
					break;
				sscanf(c+t,"%[_0-9A-Za-z]",d),t+=strlen(d);
				if(m[s=d].length())
				{
					s=m[s];
					for(ll i=0ll;i<s.length();i++)
						printf("%c",s[i]);
				}
				else
					printf("%s",d);
			}
		puts("");
	}
	return 0;
}
