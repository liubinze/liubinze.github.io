#include <bits/stdc++.h>
using namespace std;
const int N=200000+1;

int t;
int n;
int x,y,dx;
char op;
char a[N];
char r[N];
int len;
map<char,int> q;
vector<int> s[64];
vector<int> temp;
vector<int> det;
void work()
{
	int yy=1;
	for (char i='0'; i<=(9+'0'); i++)
	{
		q[i]=yy++;
	}
	for (char i='A'; i<=('Z'); i++)
	{
		q[i]=yy++;
	}
	for (char i='a'; i<=('z'); i++)
	{
		q[i]=yy++;
	}
}
void print()
{
	for (register int i=0; i<62; i++)
	{
		if (i<10)
		{
			op=i-1+'0';
		}
		else if (i<36)
		{
			op=i-11+'A';
		}
		else
		{
			op=i-37+'a';
		}
		if (s[i].size())
		{
			printf("%c:\n",op);
		}
		for (register int j=0; j<s[i].size(); j++)
		{
			printf(" %d",s[i][j]);
		}
		if (s[i].size())
		{
			puts("");
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d %d",&n,&t);
	work();
	for (register int i=1; i<=n; i++)
	{
		std::cin>>a[i];
//		printf("%d ",q[a[i]]);
		s[q[a[i]]].push_back(i);
	}
	len=n;
//	puts("");
//	for (int i=0; i<62; i++)
//	{
//		if (i<10)
//		{
//			op=i-1+'0';
//		}
//		else if (i<36)
//		{
//			op=i-11+'A';
//		}
//		else
//		{
//			op=i-37+'a';
//		}
//		if (s[i].size())
//		{
//			printf("%c:\n",op);
//		}
//		for (int j=0; j<s[i].size(); j++)
//		{
//			printf(" %d",s[i][j]);
//		}
//		if (s[i].size())
//		{
//			puts("");
//		}
//	}
//	return 0;
	while (t--)
	{
		std::cin>>x>>y>>op;
		if (x>n) continue;
		if (y>n) y=len;
		dx=q[op];
		temp.clear();
		det.clear();
		for (int i=0; i<s[dx].size(); i++)
		{
			if (! (x<=s[dx][i] && s[dx][i]<=y))
			{
				temp.push_back(s[dx][i]);
			}
			else
			{
				det.push_back(s[dx][i]);
				len--;
			}
		}
		s[dx].clear();
		for (int i=0; i<temp.size(); i++)
		{
			s[dx].push_back(temp[i]);
		}
//		printf("For %c\n",op);
//		for (int i=0; i<det.size(); i++)
//		{
//			printf(" %d\n",det[i]);
//		}
		int tp=0;
		for (register int i=1; i<62; i++)
		{
			if (i==dx) continue;
			for (register int j=0; j<s[i].size(); j++)
			{
				for (register int l=0; l<det.size(); l++)
				{
//					printf("%d %d %d %d\n",i,j,s[i][j],det[l]);
					if (s[i][j]>=det[l])
					{
						s[i][j]--;
						len--;
//						printf("%d %d %d\n",i,j,s[i][j]);
					}
				}
			}
		}
//		print();
	}
	for (register int i=1; i<62; i++)
	{
		if (i<10)
		{
			op=i-1+'0';
		}
		else if (i<36)
		{
			op=i-11+'A';
		}
		else
		{
			op=i-37+'a';
		}
		for (register int j=0; j<s[i].size(); j++)
		{
			len=max(len,s[i][j]);
			r[s[i][j]]=op;
		}
	}
	for (register int i=1; i<=len; i++)
	{
		printf("%c",r[i]);
	}
	return 0;
}
