#include <bits/stdc++.h>
#define PI 2*asin(1)
#define int long long
#define mod 1000000007
#define all(a) begin(a),end(a)
#define fore(i, j, n) for(long long i = j; i < n;i++)

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int qwe; cin >> qwe;
    while(qwe--) {
        int n;
        cin >> n;
        vector<int>a(n);
        fore(i,0,n) cin >> a[i];
        sort(all(a));
        reverse(all(a));
        int res = 0;
        fore(i,0,n){
            res = max(res, min(a[i],i + 1));
        }
        cout << res << '\n';
    }
}