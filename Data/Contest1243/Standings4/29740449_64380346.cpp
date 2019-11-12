/*input
4
5
1 2 3 4 5
6
6 5 4 3 2 1
4
8 1 6 2
9
1 9 2 8 3 7 4 6 5
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;
int main()
{
	fastio
	ll T=1,n,m;string str;
	cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		
		cin>>n;
		ll a[n];
		for(ll i=0;i < n;i++)
			cin>>a[i];
		
		sort(a,a+n, greater<int>());
		
		for (ll i = 0; i < n; ++i)
		{
			// watch(a[i]);
		}
		int high = n-1;
		int low =0;
		int mid = (high + low)/2;
		
		while(low<=high)
		{
			// count++;
			// if(count>20)
			// 	break;
			mid  = (high + low)/2;
			// if()
			if(a[mid]>mid)
			{
				sum = mid+1;
				low=mid+1;
			}
			else if(a[mid]<=mid)
			{
				high=mid-1;
			}
		}
		cout << sum << endl;
		
	}
	return 0;
}