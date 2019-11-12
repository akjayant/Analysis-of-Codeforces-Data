#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
vector<long long> a;
int main()
{
	ios_base::sync_with_stdio(false);
	long long k,i,ans,n;
	cin>>k;
	while(k--)
	{
		a.clear();
		cin>>n;
		a.resize(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		ans=1;
		for(i=0;i<n;i++)
		{
			if(a[i]>=i+1)
				ans=i+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
