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

vector<int> f[1100];
map<pair<int,int>,int> s;
int n;
double t[1100];
void dfs(int x,int fa)
{
	int p=f[x].size();
	double y;
	if (fa==0) y=0;
	else y=1.0+t[x];
	double z=2.0/(double)p;
	for (auto yy:f[x])
		if (yy!=fa)
		{
			y+=z;
			while (y>=2) y-=2;
			t[yy]=y;
			printf("1 %d ",s[{x,yy}]);
			if (y<1) printf("%d %d %.12lf\n",x,yy,y);
			else printf("%d %d %.12lf\n",yy,x,y-1);
			dfs(yy,x);
		}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		s[{x,y}]=s[{y,x}]=i;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	printf("%d\n",n-1);
	dfs(1,0);
	return 0;
}
