#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],ma,mi=1e9;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	cout<<a[m];
}

