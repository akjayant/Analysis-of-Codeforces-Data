#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 100005
#define mod 2000003
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
ll n, d;
vector<ll>v;
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> n;
    d = 3;

    if(n == 1) {
        cout << 1;
        return 0;
    }

    if(n % 2 == 0)
        v.pb(2);

    while(n % 2 == 0)
        n /= 2;

    while(d * d <= n) {
        if(n % d == 0)
            v.pb(d);

        while(n % d == 0)
            n /= d;

        d += 2;
    }

    if(n > 1)
        v.pb(n);

    if(v.size() > 1)
        cout << "1\n";
    else
        cout << v[0];

    return 0;
}
