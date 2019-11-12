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
int n, x, y, i, k, a[N], j;
string s, t;
vector<int>v;
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> k;

    for(; k; k--) {
        cin >> n;
        cin >> s >> t;
        v.clear();
        v.resize(0);

        if(s == t)
            cout << "Yes\n";
        else {
            for(i = 0; i < n; i++)
                if(s[i] != t[i])
                    v.pb(i);

            if(v.size() == 2) {
                if(s[v[0]] == s[v[1]] && t[v[1]] == t[v[0]])
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
            else
                cout << "No\n";
        }
    }

    return 0;
}
