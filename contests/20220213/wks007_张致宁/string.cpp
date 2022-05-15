#include<bits/stdc++.h>
using namespace std;
int n,l,r,m;
string s;
char ch;
stack<char>st,bk;
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=s.size()-1;i>-1;--i)st.push(s[i]);
	while(m--){
		cin>>l>>r>>ch;
		n=st.size();
		if(l>n)continue;
		r=min(n,r);
		for(int i=1;i<l;++i)bk.push(st.top()),st.pop();
		for(int i=l;i<=r;++i){
			if(st.top()==ch)st.pop();
			else bk.push(st.top()),st.pop();
		}
		while(!bk.empty())st.push(bk.top()),bk.pop();
	}
	while(!st.empty())cout<<st.top(),st.pop();
	return 0;
}
