#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ordered_set tree<ll int, null_type,less<ll int>, rb_tree_tag,tree_order_statistics_node_update> 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll int n;
	cin >> n;
	string s;
	cin >> s;
	int max1=0;
	int i1=0;
	int i2=0;
	rep(i,0,n)
	{
		rep(j,i,n)
		{
			char temp=s[i];
			s[i]=s[j];
			s[j]=temp;
			int f=1;
			int count1=0;
			int c1=0;
			int c2=0;
			rep(k,0,n)
			{
				if (s[k]=='(') c1=c1+1;
				else c1=c1-1;
				if (c1<c2)
				{
					c2=c1;
					count1=0;
				}
				if (c1==c2) count1++;
			}
			if (c1!=0) f=0;
			if (f)
			{
				if (count1>=max1)
				{
					max1=count1;
					i1=i;
					i2=j;
				}
			}
			char temp1=s[i];
			s[i]=s[j];
			s[j]=temp1;
		}
	}
	cout << max1 << endl;
	cout << i1+1 << " " << i2+1 << endl;
}