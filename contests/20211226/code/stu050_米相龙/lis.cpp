#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,last;
string ans;
int c[5005],a[5005];
stack<int>k;
int main() {
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		string b;
		for(int j=i; j<=n; j++) {
			if(a[j]>last){
				m=a[j];last=a[j];
				while(m){
					k.push(m%10);
					m/=10;
				}
				while(k.size()){
					b+=k.top()+'0';
					k.pop();
				}
				b+='A';
			}
		}
		if(b>ans) ans=b;
	}
	//cout<<ans<<endl;
	long long i;
	cnt=0;
	for(i=0;i<ans.size();){
		while(ans[i]>='0'&&ans[i]<='9'){
			c[cnt]=c[cnt]*10+ans[i]-'0';
			i++;
		}
		i++;cnt++;
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
