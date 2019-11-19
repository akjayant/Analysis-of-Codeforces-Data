/* 
 * Author: Imagine_I
 * Time: 2019-10-13 17:07:01
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int ans1=a/c,ans2=b/d;
		if(a%c)ans1++;
		if(b%d)ans2++;
		if(ans1+ans2>k) cout<<-1<<'\n';
		else cout<<ans1<<' '<<ans2<<'\n';
	}
	return 0;
}
