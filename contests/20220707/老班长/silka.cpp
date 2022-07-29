#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
int lp,li[100003],lli,e[2][1003][1003];
struct pa
{
	int c,x1,y1,x2,y2;
}p[100003];
struct SegT
{
	struct node
	{
		int lazy;
	}e[5000003];
	inline void init(int no,int lx,int ly,int rx,int ry)
	{
		if(lx>=rx||ly>=ry)
			return;
		if(lx+1<rx||ly+1<ry)
			e[no].lazy=0,init(no<<2|1,lx,ly,lx+rx>>1,ly+ry>>1),init(no<<2|2,lx,ly+ry>>1,lx+rx>>1,ry),init(no<<2|3,lx+rx>>1,ly,rx,ly+ry>>1),init(no+1<<2,lx+rx>>1,ly+ry>>1,rx,ry);
		else
			e[no].lazy=1;
		return;
	}
	inline void emplace(int c,int x1,int y1,int x2,int y2,int no,int lx,int ly,int rx,int ry)
	{
		if(x1>=rx||y1>=ry||x2<=lx||y2<=ly||lx>=rx||ly>=ry)
			return;
		if(e[no].lazy&&(lx+1<rx||ly+1<ry))
			e[no<<2|1].lazy=e[no<<2|2].lazy=e[no<<2|3].lazy=e[no+1<<2].lazy=e[no].lazy,e[no].lazy=0;
		if(x1<=lx&&y1<=ly&&x2>=rx&&y2>=ry)
			return e[no].lazy=c,void();
		return emplace(c,x1,y1,x2,y2,no<<2|1,lx,ly,lx+rx>>1,ly+ry>>1),emplace(c,x1,y1,x2,y2,no<<2|2,lx,ly+ry>>1,lx+rx>>1,ry),emplace(c,x1,y1,x2,y2,no<<2|3,lx+rx>>1,ly,rx,ly+ry>>1),emplace(c,x1,y1,x2,y2,no+1<<2,lx+rx>>1,ly+ry>>1,rx,ry);
	}
	inline void map(int mp[1003][1003],int no,int lx,int ly,int rx,int ry)
	{
		if(lx>=rx||ly>=ry)
			return;
		if(lx+1==rx&&ly+1==ry)
			return mp[lx][ly]=e[no].lazy,void();
		if(e[no].lazy&&(lx+1<rx||ly+1<ry))
			e[no<<2|1].lazy=e[no<<2|2].lazy=e[no<<2|3].lazy=e[no+1<<2].lazy=e[no].lazy,e[no].lazy=0;
		return map(mp,no<<2|1,lx,ly,lx+rx>>1,ly+ry>>1),map(mp,no<<2|2,lx,ly+ry>>1,lx+rx>>1,ry),map(mp,no<<2|3,lx+rx>>1,ly,rx,ly+ry>>1),map(mp,no+1<<2,lx+rx>>1,ly+ry>>1,rx,ry);
	}
}st[2];
int main()
{
	freopen("slika.in","r",stdin),freopen("slika.out","w",stdout);
	int n,k,m;
	char s[13];
	scanf("%d%*d%d",&n,&m),st[0].init(0,0,0,n,n),st[1].init(0,0,0,n,n);
	while(m--)
	{
		scanf("%s",s);
		if((s[0]|' ')=='p')
			scanf("%d%d%d%d%d",&p[lp].c,&p[lp].x1,&p[lp].y1,&p[lp].x2,&p[lp].y2),lp++;
		else if((s[0]|' ')=='s')
			li[lli++]=lp;
		else
			scanf("%d",&k),lp=li[k-1];
	}
	for(int i=0;i<lp;i++)
		st[p[i].x1+p[i].y1&1].emplace(p[i].c,p[i].x1,p[i].y1,p[i].x2+1,p[i].y2+1,0,0,0,n,n);
	st[0].map(e[0],0,0,0,n,n),st[1].map(e[1],0,0,0,n,n);
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<n;j++)
			printf("%d ",e[i+j&1][i][j]);
	return 0;
}
