#include<bits/stdc++.h>
using namespace std;
int n;
int f(int x)
{
	int cnt=0;
	for(int i=2;i<=x;i++)
	{
		if(x%i==0)
		{
			int k=0;
			while(x%i==0)
			{
				k++;
				x/=i;
			}
			cnt=max(cnt,k);
		}
	}
	return cnt;
}
int g(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
	{
		if(x%i==0)
		{
			ans+=x/i*f(i);
		}
	}
	return ans;
}
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		cout << g(t) << endl;
	}
	return 0;
}
