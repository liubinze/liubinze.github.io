#include<bits/stdc++.h>
using namespace std;
int t,ans[1000001];
int find(int x)
{
	int jw=0,k=0,koq=0;
	while(x>0)
	{
	koq++;
	int w=x>>1;w*=2; 
	if(w^x==1&&w!=x&&jw==0)
	{
	jw=1;
	k=koq;
	}	
	else
	{
		if(jw==1&&w^x==0)
		return 0;
	}
	x/=2;
	}
	return k;
}
int find_(int x)
{
	int jw=0,k,koq=0;
	while(x>0)
	{
	koq++;
	x/=2;
	}
	return koq;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t>0)
	{
		t--;
		int n,m,bushu=0,change=1,ke=0,jk,mo=1,most=0,many=0,bushu_=0,qi=1;
		scanf("%d%d",&n,&m);
		jk=m;
		while(mo<=n)
		{
			most++;
			mo*=2;
		}
		if(m==0)
		{
		printf("YES\n0\n");
		continue;
		}

		int kegai=m+1;	
		while(change<=n)
		{
		many++; 
		int w=find(jk);
		if(w==many)
		{
			int qw=find_(jk);
			if(qw<=most)
			{
				bushu+=qw-w+1;
				ke=1;
				for(int i=bushu_+1;i<=bushu;i++)
				{
					ans[i]=qi;
					qi=qi+change;
					change*=2;
				}
				break;
			}
		}
		bushu++;
		bushu_=bushu;
		jk+=change;
		ans[bushu]=kegai;
		kegai+=change;
		change*=2;
		}
		if(ke==1)
		{
			printf("YES\n");
			printf("%d\n",bushu);
			for(int i=1;i<=bushu;i++)
			printf("%d ",ans[i]);
			printf("\n");
		}
		else
		printf("No\n");
	}
}
