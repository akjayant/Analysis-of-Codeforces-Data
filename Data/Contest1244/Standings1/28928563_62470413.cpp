/* 
 * Author: Imagine_I
 * Time: 2019-10-13 17:13:54
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
string book;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>book;
		int p=0,l=n-1;
		bool f=true;
		for(int i=0;i<n;i++)
		{
			if(book[i]=='1') l=min(l,i),p=max(p,i),f=false;
		}
		if(f)
		{
			cout<<n<<'\n';
			continue;
		}
		int ans=min(l,n-1-p);
		cout<<2*(n-ans)<<'\n';
	}
	return 0;
}
