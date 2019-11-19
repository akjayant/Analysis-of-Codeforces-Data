#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define mod (ll)(1e9+7)
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int main()
{
	
	ll t;
	cin >> t;
	while(t--){
	int n;
	cin >> n;
	string s;
	cin >> s;

	int arr[n+1] = {0};

	for (int i = 0; i < n; ++i)
	{
		if(s[i] == '1')
			arr[i] = 1;
	}

	int baseans = n;
	for (int i = 0; i < n ; ++i)
	{
		if(arr[i]){
			int tmx = 2*n - min(2*i,2*(n-1-i));
			baseans = max(baseans,tmx);
		}
	}
	cout << baseans << endl;
	}
}