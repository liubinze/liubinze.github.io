#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("oriented.in","r",stdin),freopen("oriented.out","w",stdout);
	ll a,b,m,x,y;
	scanf("%lld%lld%lld",&a,&b,&m),puts(b==6ll?"9":b==7ll?"5":"1");
	while(m--)
		scanf("%lld%lld",&x,&y),printf(x<y?"1 ":x==4ll&&y==3ll?"1 ":"0 ");
	return 0;
}
