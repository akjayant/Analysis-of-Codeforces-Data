#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<vector>
#include<utility>
#include<cmath>
#include<iostream>
#include<set>
using namespace std;

set <int> st;
unordered_map <int,long long> mp;
int a[100005];
long long min(long long x,long long y)
{
	return x<y?x:y;
}
int main()
{
	int n;long long k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		mp[x]++;a[i]=x;
		st.insert(x);
	}
	set<int>::iterator bgn=st.begin();
	set<int>::iterator end=st.end();
	--end;
	while(k>0)
	{
		set<int>::iterator bgn=st.begin();
		set<int>::iterator end=st.end();--end;
		int x=*bgn;
		int y=*end;
		if(x==y) break;
		if(mp[x]<mp[y])
		{
			if(k<mp[x]) break;
			bgn++;
			int delta=*bgn-x;
			int Min=min(delta,k/mp[x]);
			k-=Min*mp[x];
			st.erase(x);
			st.insert(x+Min);
			mp[x+Min]+=mp[x];
		}
		else
		{
			if(k<mp[y]) break;
			end--;
			int delta=y-*end;
			int Min=min(delta,k/mp[y]);
			k-=Min*mp[y];
			st.erase(y);
			st.insert(y-Min);
			mp[y-Min]+=mp[y];
		}
	}
	bgn=st.begin();
	end=st.end();
	--end;
	int ans=*end-*bgn;
	printf("%d",ans);
	return 0;
} 
