#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin >> n >> m >> k)
	{
		int a[100005],b[100005];
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			b[i]=a[i];
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]==b[i])
				{
					a[j]=0;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
