#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,M=15;

int n,m,k,a[N];
bool mark[N];
vector<int> vt[M];

int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin>>n>>m>>k)
	{
		memset(mark,false,sizeof mark);
		for(int i=1;i<=k;i++)
		{
			vt[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			vt[a[i]].push_back(i);
		}
		for(int i=1;i<=k;i++)
			for(int j=0;j<vt[i].size()&&m;j++)
			{
				if(mark[vt[i][j]])continue;
				if(i==k)
				{
					m--,mark[vt[i][j]]=true;
					continue;
				}
				int cnt=0;
				for(int k=1;k<vt[i][j];k++)
				{
					if(mark[k])continue;
					if(a[k]>a[vt[i][j]])cnt++;
				}
				if(m>=cnt)
				{
					for(int k=1;k<vt[i][j];k++)
						if(!mark[k]&&a[k]>a[vt[i][j]])
							mark[k]=true;
					m-=cnt;
				}
				else break;
			}
		for(int i=1;i<=n;i++)
			if(!mark[i])
				printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
