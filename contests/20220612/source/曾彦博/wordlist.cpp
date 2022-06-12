#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1 << 20;  
char buf[SIZE],*p1,*p2;  
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)  

void read(long long &x) 
{  
    x = 0;  
    char ch;  
    while(!isdigit(ch = gc));  
    do 
	{  
        x = x * 10 + ch - '0';  
    }while(isdigit(ch = gc));  
} 

const long long N = 1e6;

long long n,w,tot,len[N | 5];

long long Max(long long x,long long y)
{
	return x > y ? x : y;
}

bool check(long long mid)
{
	long long res = 0,k = 0;
	for(long long i = 1;i <= n;i += mid)
	{
		long long maxn = 0;
		for(long long j = i;j <= i + mid - 1 && j <= n;j++) maxn = Max(maxn,len[j]);
		res += maxn;
		k++;
	}
	return res + k - 1 <= w;
}

int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n),read(w);
	for(long long i = 1;i <= n;i++) read(len[i]);
	long long l = 1,r = n;
	while(l < r)
	{
		long long mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld",l);
	return 0;
}
