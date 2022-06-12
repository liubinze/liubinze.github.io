#include<stdio.h>
#include<algorithm>
//#include<time.h>
int T;
int n,m;
char s[30];
int a[30][30],ah[30][30],ahn[30],al[30][30],aln[30];
bool aa[30][30][30][30];
bool h[30],l[30];
int bh[30],bl[30];
int ans;
long long ppp,pppp;
bool check(int x,int y)
{
	for(int i=1;i<=x;i++)
	{
		if(bh[i]==0)
		{
			for(int j=1;j<=ahn[i];j++)
			{
				if(ah[i][j]>y)
				{
					break;
				}
				if(bl[ah[i][j]]==0)
				{
					return false;
				}
			}
		}
	}
	return true;
}
void dfs(int x,int li,int lj)
{
	ppp++;
	pppp++;
	if(ppp>=600000||pppp>=2500000)
	{
		return;
	}
	if(check(n,m))
	{
		ans=std::min(x,ans);
	}
	else if(x<ans)
	{
//		for(int i=li+1;i<=n;i++)
//		{
//			for(int j=lj+1;j<=m;j++)
//			{
//				if((h[i]||l[j])&&!aa[li+1][lj+1][i-1][j-1]&&check(i-1,j-1))
//				{
//					bh[i]++;
//					bl[j]++;
//					dfs(x+1,i,j);
//					bh[i]--;
//					bl[j]--;
//				}
//			}
//		}
		for(int i=n;i>li;i--)
		{
			for(int j=m;j>lj;j--)
			{
				if((h[i]||l[j])&&!aa[li+1][lj+1][i-1][j-1]&&check(i-1,j-1))
				{
					bh[i]++;
					bl[j]++;
					dfs(x+1,i,j);
					bh[i]--;
					bl[j]--;
				}
			}
		}
	}
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=std::min(n,m);
		for(int i=1;i<=n;i++)
		{
			h[i]=false;
			ahn[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			l[i]=false;
			aln[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int ii=1;ii<=n;ii++)
				{
					for(int jj=1;jj<=m;jj++)
					{
						aa[i][j][ii][jj]=false;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",&s);
			for(int j=1;j<=m;j++)
			{
				a[i][j]=(s[j-1]=='*');
				if(a[i][j]==1)
				{
					h[i]=true;
					l[j]=true;
					ahn[i]++;
					ah[i][ahn[i]]=j;
					aln[i]++;
					al[j][aln[j]]=i;
					for(int ii=1;ii<=i;ii++)
					{
						for(int jj=1;jj<=j;jj++)
						{
							aa[ii][jj][i][j]=true;
						}
					}
				}
				else
				{
					for(int ii=1;ii<i;ii++)
					{
						for(int jj=1;jj<j;jj++)
						{
							aa[ii][jj][i][j]=aa[ii][jj][i-1][j]||aa[ii][jj][i][j-1];
						}
					}
					for(int ii=1;ii<i;ii++)
					{
						aa[ii][j][i][j]=aa[ii][j][i-1][j];
					}
					for(int jj=1;jj<j;jj++)
					{
						aa[i][jj][i][j]=aa[i][jj][i][j-1];
					}
					aa[i][j][i][j]=false;
				}
			}
		}
		ppp=0;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
