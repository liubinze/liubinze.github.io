#include<bits/stdc++.h>
using namespace std;
const int SIZE=1<<20;
char buf[SIZE],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)
void read(int &x)
{
	x=0;
	char ch;
	while(!isdigit(ch=gc));
	do
	{
		x=x*10+ch-'0'; 
	}while(isdigit(ch=gc));
}
int n,w,a[1000001],ans,ans1,flag,b[1000001];
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n);
	read(w);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		b[i]=a[i];
		if(a[i]==w)flag=1;
	}
	if(flag)
	{
		cout<<1;
		return 0;
	}
	sort(b+1,b+1+n);
	if(b[1]+b[n]>w)
	{
		cout<<1;
		return 0;
	}
	for(int i=1,cnt=0,sum=0;i<=n;i++)
	{
		sum+=a[i];
		if(sum<=w)cnt++;
		else 
		{
			ans=cnt;
			break;
		}
	}
	for(int i=n,cnt=0,sum=0;i>=1;i--)
	{
		sum+=a[i];
		if(sum<=w)cnt++;
		else 
		{
			ans1=cnt;
			break;
		}
	}cout<<min(ans1,ans);
}
