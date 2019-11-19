#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define M 1000000007
#define pi 3.141592653589793
#define pb push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define tc int t;cin>>t;while(t--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    fastio;
    tc {
        int n, m;
        cin >> n;
        ll a0 = 0, a1 = 0, b0 = 0, b1 = 0, c;
        while (n--) {
            cin >> c;
            if (c % 2)
                a1++;
            else a0++;
        }
        cin >> m;
        while (m--) {
            cin >> c;
            if (c % 2)
                b1++;
            else b0++;
        }
        cout << a0 * b0 + a1 * b1 << "\n";
    }
}