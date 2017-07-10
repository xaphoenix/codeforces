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
int n,m;
string s,t;
int ans=1100;
vector<int> way,tmp; 
int main()
{
	cin>>n>>m;
	cin>>s>>t;
	for (int i=1;i+n-1<=m;i++)
	{
		int num=0;
		tmp.clear();
		for (int j=1;j<=n;j++)
			if (s[j-1]!=t[i+j-2]) num++,tmp.push_back(j);
		if (num<ans)
		{
			ans=min(ans,num);
			way=tmp;
		}
	}
	cout<<ans<<endl;
	for (int i=0;i<ans;i++)
		cout<<way[i]<<" ";
	return 0;
}
