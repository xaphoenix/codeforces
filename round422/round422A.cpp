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

typedef long long LL;

LL ans=1;
int a,b;
int main()
{
	cin>>a>>b;
	for (int i=1;i<=min(a,b);i++)
		ans*=(LL)i;
	cout<<ans<<endl;
	return 0;
}
