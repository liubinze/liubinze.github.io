#include<bits/stdc++.h>
using namespace std;
int q;
long long l,r;
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&q);
	while(q>0){
		q--;
		scanf("%lld%lld",&l,&r);
		long long  p=l,k=r,ans=0,w,kq;
		if(l/10==r/10)
		{
			for(int i=l;i<=r;i++)
		{
		if(i%9!=0)
		ans+=i%9;
		else
		ans+=9;
		}
		}
		else
		{
		if(l%10!=0)
		p=l+(10-l%10);
		if(r%10!=0)
		k=r-(r%10);
		ans+=(k-p)/10*45;
		for(int i=l;i<p;i++)
		{
		if(i%9!=0)
		ans+=i%9;
		else
		ans+=9;
		}
		for(int i=r;i>k;i--)
		{
		if(i%9!=0)
		ans+=i%9;
		else
		ans+=9;
		}			
		}
		w=(p-10)%9;
		if(w==0)
		w=9;
		kq=(k-p)/10;
		long long po=kq/9;
		ans+=po*45;
		for(long long  i=p+po*90;i<=k;i+=10)
		{
		if(i%9!=0)
		ans+=i%9;
		else
		ans+=9;
		}		
		printf("%lld",ans);
		cout<<endl;
	}
}
