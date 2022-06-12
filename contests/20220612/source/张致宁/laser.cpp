#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char ch;
main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<"Yes\n";
		if(n<m){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					cin>>ch;
					if(ch=='S')cout<<'|';
					else cout<<ch;
				}
				cout<<endl;
			}
		}else{
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					cin>>ch;
					if(ch=='S')cout<<'-';
					else cout<<ch;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
