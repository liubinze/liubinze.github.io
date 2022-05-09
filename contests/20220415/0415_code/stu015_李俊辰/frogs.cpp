#include<bits/stdc++.h>
using namespace std;
int n,m,zhi[10001];
long long  zong;
bool er[100000001];
int main()
{	
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&zhi[i]);
	for(int i=1;i<=n;i++)
	{
//	cout<<i<<":";
	int a=0,p=0;
	while(a!=0||p==0){
	
		a=(a+zhi[i])%m;
		if(er[a]==false)
		{
		zong+=a;
		er[a]=true;
		}
		p++;
	}		
//	cout<<endl;
	}
	cout<<zong;
}
