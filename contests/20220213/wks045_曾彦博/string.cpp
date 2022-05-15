#include <bits/stdc++.h>
using namespace std;

struct Tree 
{
	int l,r,sum[105],cnt;
	vector<int> lazy;
}tree[200005];

string s;
int n,m,a[200005],idx[200005],go[200005],tot;
int CNT;
char ans[200005];
bool flag;

inline void push_up(int p) 
{
	for(int i = 1;i <= 62;i++) tree[p].sum[i] = tree[p << 1].sum[i] + tree[p << 1 | 1].sum[i];
}

void push_down(int p)
{
	for(int i = 0;i < tree[p].lazy.size();i++)
	{
		int tmp = tree[p].lazy[i];
		tree[p << 1].cnt += tree[p << 1].sum[tmp];
		tree[p << 1].lazy.push_back(tmp);
		tree[p << 1 | 1].cnt += tree[p << 1 | 1].sum[tmp];
		tree[p << 1 | 1].lazy.push_back(tmp);
	}
	tree[p].lazy.clear();
}

void build(int p,int x,int y)
{
	tree[p].l = x,tree[p].r = y;
	if(x == y) tree[p].sum[a[x]]++;
	else
	{
		int mid = (x + y) >> 1;
		build(p << 1,x,mid);
		build(p << 1 | 1,mid + 1,y);
		push_up(p);
	}
}

void add(int p,int x,int y,int z) 
{
	if(tree[p].lazy.size()) push_down(p);
	if(x <= tree[p].l && tree[p].r <= y)
	{
		tree[p].cnt += tree[p].sum[z];
		tree[p].lazy.push_back(z);
		tree[p].sum[z] = 0;
	}
	else
	{
		int mid = (tree[p].l + tree[p].r) >> 1;
		if(x <= mid) add(p << 1,x,y,z);
		if(y > mid) add(p << 1 | 1,x,y,z);
		tree[p].cnt = tree[p << 1].cnt + tree[p << 1 | 1].cnt;
		tree[p].sum[z] = tree[p << 1].sum[z] + tree[p << 1 | 1].sum[z];
	}
}

int query(int p,int x,int y)
{
	if(tree[p].lazy.size()) push_down(p);
	if(x <= tree[p].l && tree[p].r <= y) return tree[p].cnt;
	else
	{
		int mid = (tree[p].l + tree[p].r) >> 1,res = 0;
		if(x <= mid) res += query(p << 1,x,y);
		if(y > mid) res += query(p << 1 | 1,x,y);
		return res;
	}
}

bool check(int mid,int x)
{
	return mid - query(1,1,mid - 1) <= x;
}

int Find(int x)
{
	int l = x,r = n;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid,x)) l = mid + 1;
		else r = mid - 1;
	}
	if(check(l - 1,x)) l--;
	return l;
}

signed main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin >> s;
	for(int i = 1;i <= n;i++) 
	{
		if(s[i - 1] >= 'a' && s[i - 1] <= 'z') a[i] = s[i - 1] - 'a' + 1;
		else if(s[i - 1] >= 'A' && s[i - 1] <= 'Z') a[i] = s[i - 1] - 'A' + 27;
		else a[i] = s[i - 1] - '0' + 53;
	}
	build(1,1,n);
	while(m--) 
	{
		CNT++;
		int x,y,z;
		char op;
		scanf("%d %d %c",&x,&y,&op);
		x = Find(x),y = Find(y);
		if(op >= 'a' && op <= 'z') z = op - 'a' + 1;
		else if(op >= 'A' && op <= 'Z') z = op - 'A' + 27;
		else z = op - '0' + 53;
		if(x == 1 && a[0] == z) flag = true;
		add(1,x,y,z);
	}
	if(flag) ans[1] = s[0],tot++;
	for(int i = 2;i <= n;i++)
	{
		int tmp = query(1,1,i);
		if(!ans[i - tmp]) ans[i - tmp] = s[i - 1],tot++;
	}
	for(int i = 1;i <= tot;i++) printf("%c",ans[i]);
	return 0;
}
