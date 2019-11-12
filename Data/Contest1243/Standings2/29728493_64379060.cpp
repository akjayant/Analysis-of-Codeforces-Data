#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

string s, t;
vector<int> v;
int n, T;

bool can(){
    if(s == t)
        return 1;
    if(v.size() == 2){
        swap(s[v[0]], t[v[1]]);
        if(s == t)
            return 1;
        swap(s[v[0]], t[v[1]]);
        swap(s[v[1]], t[v[0]]);
        return s == t;
    }
    return 0;
}

int main()
{
    cin >> T;
    while(T--){
        cin >> n >> s >> t;
        v.clear();
        for(int i = 0; i < n; i++)
            if(s[i] != t[i])
                v.pb(i);
        puts(can() ? "Yes" : "No");
    }
    return 0;
}
