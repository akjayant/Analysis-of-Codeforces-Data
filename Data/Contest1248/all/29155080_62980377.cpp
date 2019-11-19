#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    ll q, n, m, a, b, c, d, x; cin >> q;
    vector<ll> ans;
    for(int i=0;i<q;i++) {
        a=b=c=d=0;
        cin >> n;
        for(int j=0;j<n;j++) {
            cin >> x;
            if(x&1) a++;
            else b++;
        }
        cin >> m;
        for(int j=0;j<m;j++) {
            cin >> x;
            if(x&1) c++;
            else d++;
        }
        cout << a*c + b*d << endl;
    }
    return 0;
}
