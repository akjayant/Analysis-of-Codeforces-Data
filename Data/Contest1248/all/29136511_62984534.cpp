#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define debug(i) cout << i << endl;
#define debugarr(a) for(auto i : a) cout << i << " ";

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    reverse(arr, arr + n);
    int l = 0;
    int r = n-1;
    ll x=0;
    ll y=0;
    while(l <= r) {
        x += arr[l];
        if(l != r)
            y += arr[r];
        l++;
        r--;
    }
    ll ans = x*x+y*y;
    cout << ans << endl;
}
