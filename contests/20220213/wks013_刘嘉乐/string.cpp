#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
char s[200005],c[5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		scanf("%s",c);
		if(x>n)continue;
		if(y>n)y=n;
		int k=n;
		for(int i=x;i<=y;i++)if(s[i]==c[0])s[i]='!',k--;
		for(int i=x,j=x;i<=n;i++)if(s[i]!='!')s[j++]=s[i];
		n=k;
	}
	for(int i=1;i<=n;i++)printf("%c",s[i]);
	return 0;
}
