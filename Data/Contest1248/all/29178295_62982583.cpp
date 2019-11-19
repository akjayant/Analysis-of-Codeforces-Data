#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back 
#define ins insert
#define rs resize
#define br break;
#define cont continue;
#define vi vector<ll>
#define vll vector<long long>
#define si set<ll>
#define sll set<long long>
#define pii pair<ll,ll>
#define pll pair<long long, long long>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vec vector
#define cend cout<<endl;
#define sc second
#define fr first
#define retz return 0;
#define ll_MAX (ll)(1e9*1e9)
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b)  for(int i=a; i<=b; i++)
#define repd(i,a,b) for(int i=a; i>=b; i--)
#define ps(arr, n) for(int i=1; i<n; i++)arr[i]+=arr[i-1];
#define inp(arr, n)for(int i=0; i<n; i++)cin>>arr[i];
#define out(arr, n)for(int i=0; i<n; i++)cout<<arr[i];
#define inp1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define out1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define loop(q) for(auto it:q)
#define loop1(q) for(auto&it:q)
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////



void solve()
{
	int n;
	cin >> n;
	int arr[n];
	inp(arr,n);
	sort(arr,arr+n);
	int c1 = 0, c2 = 0;
	for(int i=0; i<n/2; i++)
	{
		c1 += arr[i];
	}
	for(int i=n/2; i<n; i++)
	{
		c2 += arr[i];
	}
	cout << c1*c1 + c2*c2 << endl;
}




int32_t main()
{
    speed
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}