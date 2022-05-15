#include<bits/stdc++.h>
using namespace std;
char x[200005];
int n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",x+1);
	while(m--){
		int l,r;
		char s[2];
		scanf("%d%d",&l,&r);
		scanf("%s",s+1);
		int cntl=0,cntr=0;
		for(int i=1;i<=n;i++){
			if(x[i]!='|')cntl++,cntr++;
			if(cntl>=l&&cntr<=r){
				if(x[i]==s[1])
				x[i]='|';
			}
			if(cntr>r)break;
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i]!='|')putchar(x[i]);
	}
	return 0;
}
