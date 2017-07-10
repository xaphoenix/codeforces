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
const LL mod=1e9+7;
LL f[5100000];
LL ans,now=1;
LL cal(LL x)
{
	return x*(x-1LL)/2LL;
}

LL t,l,r;
int main()
{
	cin>>t>>l>>r;
	for (int i=1;i<=r;i++)
		f[i]=1e18;
	f[1]=0;
	for (int i=1;i<r;i++)
	{
		for (int j=2;i*j<=r;j++)
		{
			int x=j*i;
			f[x]=min(f[x],f[i]+x*(LL)(j-1)/2LL);
		}
	}
	for (int i=l;i<=r;i++)
		ans=(ans+f[i]%mod*now)%mod,now=now*t%mod;
	cout<<ans<<endl;
	return 0;
}
