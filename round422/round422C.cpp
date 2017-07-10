#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>

using namespace std;
int f[210000];
struct node
{
	int l,r,x;
}a[210000];
vector<node> b[210000],c[210000];
int n,x;
int ans;
int main()
{
	scanf("%d %d",&n,&x);
	memset(f,-1,sizeof(f));
	ans=(2e9)+1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].l,&a[i].r,&a[i].x);
		b[a[i].l].push_back(a[i]);
		c[a[i].r].push_back(a[i]);
	}
	for (int i=200000;i;i--)
	{
		for (int j=0;j<c[i].size();j++)
		{
			node p=c[i][j];
			if (c[i][j].r-c[i][j].l+1>x) continue;
			if (f[x-(c[i][j].r-c[i][j].l+1)]==-1) continue;
			ans=min(ans,c[i][j].x+f[x-(c[i][j].r-c[i][j].l+1)]);
		}
		for (int j=0;j<b[i].size();j++)
		{
			node p=b[i][j];
			if (f[b[i][j].r-b[i][j].l+1]==-1) f[b[i][j].r-b[i][j].l+1]=b[i][j].x;
			f[b[i][j].r-b[i][j].l+1]=min(f[b[i][j].r-b[i][j].l+1],b[i][j].x);
		}
	}
	if (ans==(2e9)+1) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
