#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int bl[65];
char s[200005],C[5],c;
struct tree{
	int l,r,len;
	int c[65];
	int s;
}t[1000000];
void tre(int q,int l,int r){
	t[q].l=l;t[q].r=r;
	t[q].len=r-l+1;
	if(l==r){
		if('0'<=s[l-1]&&s[l-1]<='9'){
			t[q].c[s[l-1]-'0']++;
			t[q].s=s[l-1]-'0';
		}
		else{
			if('A'<=s[l-1]&&s[l-1]<='Z'){
				t[q].c[(s[l-1]-'A')+10]++;
			    t[q].s=(s[l-1]-'A')+10;
			}
			else{
			    t[q].c[(s[l-1]-'a')+36]++;
			    t[q].s=(s[l-1]-'a')+36;
			}
		}
		//cout<<t[q].s<<" ";
	    return;
	}
	int mid=(l+r)/2;
	tre(q*2,l,mid);
	tre(q*2+1,mid+1,r);
	for(int i=0;i<62;i++){
		t[q].c[i]=t[q*2].c[i]+t[q*2+1].c[i];
	}
}
void del(int q,int a,int b,char c){
	//cout<<t[q].l<<" "<<t[q].r<<" "<<t[q*2].len<<endl;
	if(a==1&&b==t[q].len){
		if('0'<=c&&c<='9'){
			t[q].len-=t[q].c[c-'0'];
			t[q].c[c-'0']=0;
		}
		else{
			if('A'<=c&&c<='Z'){
				t[q].len-=t[q].c[(c-'A')+10];
				t[q].c[(c-'A')+10]=0;
			}
			else{
				t[q].len-=t[q].c[(c-'a')+36];
			    t[q].c[(c-'a')+36]=0;
			}
		}
		return;
	}
	for(int i=0;i<62;i++){
		if(t[q].c[i]==0){
			t[q*2].len-=t[q*2].c[i];
			t[q*2].c[i]=0;
			t[q*2+1].len-=t[q*2+1].c[i];
			t[q*2+1].c[i]=0;
		}
	}
	int mid=t[q*2].len;
	if(a<=mid) del(q*2,a,min(b,mid),c);
	if(mid<b) del(q*2+1,max(1,a-mid),b-mid,c);
	for(int i=0;i<62;i++){
		t[q].c[i]=t[q*2].c[i]+t[q*2+1].c[i];
	}
	t[q].len=t[q*2].len+t[q*2+1].len;
}
void get(int q){
    //cout<<t[q].l<<" "<<t[q].r<<" "<<t[q*2].len<<endl;
	if(t[q].len==0) return;
	if(t[q].l==t[q].r){
		if(bl[t[q].s]==0){
			if(t[q].s<10){
				printf("%c",t[q].s+'0');
			}
			else{
				if(t[q].s<36){
					printf("%c",(t[q].s-10)+'A');
				}
				else{
					printf("%c",(t[q].s-36)+'a');
				}
			}
		}
		return;
	}
	for(int i=0;i<62;i++){
		if(t[q].c[i]==0) bl[i]++; 
	}
	get(q*2);
	get(q*2+1);
	for(int i=0;i<62;i++){
		if(t[q].c[i]==0) bl[i]--; 
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d%s",&n,&m,&s);
	tre(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%s",&a,&b,&C);
		if(a>t[1].len) continue;
		if(b>t[1].len) b=t[1].len;
		del(1,a,b,C[0]);
	}
	get(1);
}
