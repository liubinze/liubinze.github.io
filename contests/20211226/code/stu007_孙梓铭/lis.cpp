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
#define mp make_pair
int sz[5005],dp[5005][2]; 
queue<pair<int,int> > sss;
inline void add(int a,string *b)
{
	string dq;
	while(a!=0)
	{
		dq=char(a%10+'0')+dq;
		a/=10;
	}
	*b+=dq+' ';
}
signed main(signed argc,char **argv)
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
    r int n=read(),is=0,js=0,ans=0;
    for(r int i=1;i<=n;++i) sz[i]=read(),dp[i][i&1]=1;
    for(r int i=1;i<=n;++i)
    {
    	int zj;
    	bool pd=0;
    	for(r int j=i+1;j<=n;++j)
    	{
    		if(sz[j]>=sz[i]) 
			{
				zj=j;
				pd=1;
				dp[i][j&1]=2;
				break;
			}
		}
		dp[i][i&1]=1;
    	if(!pd) continue;
        for(r int j=i+1;j<=n;++j)
        {
        	dp[i][j&1]=0;
        	if(sz[j]<sz[i]) dp[i][j&1]=dp[i][j-1&1];
            else if(sz[j]>sz[j-1]) dp[i][j&1]=dp[i][j-1&1]+1;
            else dp[i][j&1]=dp[i][j-1&1];
            if(dp[i][j&1]==dp[is][js&1])
            {
            	sss.push(mp(i,j));
			}
            else if(dp[i][j&1]>dp[is][js&1]) 
            {
            	while(!sss.empty()) sss.pop();	
            	sss.push(mp(i,j));
            	is=i;
            	js=j;
			}
			ans=max(ans,dp[i][j&1]);
        }
    }
    printf("%d\n",ans);
    string a="",anss="";
    while(!sss.empty())
    {	
		pair<int,int> dq=sss.front();
    	sss.pop();
    	r int x=sz[dq.first];
    	add(sz[dq.first],&a);
    	for(r int i=dq.first+1;i<=dq.second;++i)
    	{
    		if(sz[i]>x)
    		{
    			add(sz[i],&a);
    			x=sz[i];
			}
		}
		anss=max(anss,a);
		a="";
	}
	for(r int i=0;i<anss.length();++i) putchar(anss[i]);
	exit(0);
}

