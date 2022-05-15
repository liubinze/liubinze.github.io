#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
int a[N], fa[N], val[N];
int f[N];
int ff[N];

int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",a + i);
	}
	f[1] = a[1];
	ff[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		f[i] = max(f[i - 1] + a[i], a[i]);
		ff[i] = min(ff[i - 1] + a[i], a[i]);
	}
	sort(f + 1, f + 1 + n);
	sort(ff + 1, ff + 1 + n);
	cout << min(f[m - 1], f[n - m + 1]);
	return 0;
}
/*
4 2
3 -2 4 -2
*/
