#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1 << 20;
char buf[SIZE], *p1, *p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)
void read(int &x)
{
	x = 0;
	char ch;
	while(!isdigit(ch = gc));
	do
	{
		x = x * 10 + ch - '0';
	}
	while(isdigit(ch = gc));
}

const int N = 1e6 + 5;

int n,w;
int a[N];

bool check(int l)
{
	int Ans = 0;
	for(int i = 1; i <= n; i += l)
	{
		int sum = 0;
		for(int j = i; j < i + l; j++) sum = max(sum,a[j]);
		Ans += sum + 1;
	}
	if(Ans - 1 <= w) return 1;
	return 0;
}

signed main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	scanf("%d %d",&n,&w);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1; i; i++) if(check(i)) return printf("%d",i),0;
	return 0;
}
