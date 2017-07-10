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

int f[51],g[51];
int n,m,x;
char s[110000],t[110000];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&m);
	scanf("%s",t+1);
	scanf("%d",&x);
	for (int i=1;i<=n;i++)
		for (int j=0;j<x;j++)
		{
			int p=f[j];
			int k=1;
			if (g[j]>=i) continue;
			while (s[i+k-1]==t[p+k]&&p+k<=m) k++;
			if (f[j+1]<p+k-1) f[j+1]=p+k-1,g[j+1]=i+k-2;
			if (f[j+1]==m) return printf("YES\n"),0;
		}
	printf("NO\n");
	return 0;
}
