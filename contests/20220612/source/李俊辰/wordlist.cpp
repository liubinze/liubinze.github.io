#include<bits/stdc++.h>
using namespace std;
  const int SIZE = 1 << 20;  
  char buf[SIZE], *p1, *p2;  
 #define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)  
 void read(int &x) {  
     x = 0;  
     char ch;  
     while(!isdigit(ch = gc));  
     do {  
        x = x*10 + ch -  '0';  
     }while(isdigit(ch = gc));  
  } 
int h[1000001],n,w,a[1000001],l[100001],ans=1,ll;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
 	freopen("wordlist.in","r",stdin);
    freopen("wordlist.out","w",stdout);
	cin>>n>>w;
	w++;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	for(int i=1;i<=n;i++)
	h[i]=1;
//	dfs(1,0,w+1,0);
	sort(a+1,a+1+n);
	int k=ll+1;
	for(;k>=1;k--)
	{
	//	cout<<k<<" "<<n<<" "<<ans<<" "<<h[k]<<endl;
		if(n==0)
		break;
		if(k==ll+1)
		{
			if(w-a[n]-1>=0)
			{
				w-=a[n]+1;
				ll++;
				n--;
				k=ll+2;
			}
		}
		else if(h[k]<ans)
		{
			h[k]++;
			n--;
			k=ll+2;
		}
		else if(k==1)
		{
			ans++;
			h[k]++;
			n--;
			k=ll+2;
		}
	
	}
	cout<<ans;

}
