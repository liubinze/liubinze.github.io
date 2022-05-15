#include<bits/stdc++.h>
using namespace std;
int T;
unsigned long long n,k,m[100];
unsigned long long func(unsigned long long n) { 
    unsigned long long x = n & (-n); 
    return ( (n + x) % m[k] ) | ((( ( ( n ^ (n + x) ) % m[k] ) / x) >> 2ll)%m[k]); 
} 
int main(){
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	m[0]=1;
	for(int i=1;i<=100;i++) m[i]=m[i-1]*2;
	scanf("%d",&T);
	while(T--){
		cin>>n>>k;
		printf("%llu\n",func(n)%m[k]);
	}
}
