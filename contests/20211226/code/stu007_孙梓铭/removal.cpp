#include<bits/stdc++.h>
#define ll long long
#define r register
using namespace std;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

priority_queue<int> re;
int sz[100005];
signed main(signed argc,char **argv)
{
	freopen("removal2.in","r",stdin);
	freopen("out.out","w",stdout);
	r int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		r int o=1;
		for(r int i=1;i<=n;++i) sz[i]=read();
		while(m>0&&o<n)
		{
			if(sz[o]==-1) 
			{
				++o;
				continue;
			}
			r int mins,mind=o;
			for(r int i=o+1;i<=o+m;++i) if(sz[i]<sz[mind]) 
			{
				mind=i;
			}
			for(r int i=o;i<mind;++i)sz[i]=-1,--m;
			++o;
		}
		for(r int i=n;m>0;--i) if(sz[i]!=-1) sz[i]=-1,--m;
		for(r int i=1;i<=n;++i) if(sz[i]!=-1) printf("%d ",sz[i]);
		puts("");
		
	}
	exit(0);
}

