#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
# include <math.h>
#define lli long long int
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;

lli cnt1[40], cnt2[40];
bool vis[60];

void solve()
{
    lli n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    /*
    for(int i = 0 ; i < 40; i ++) {
        cnt1[i] = 0;
        cnt2[i] = 0;
    }
    for(int i = 0; i < n; i ++) {
        cnt1[s[i] - 'a'] ++;
    }
    for(int i = 0; i < n; i ++) {
        cnt2[t[i] - 'a'] ++;
    }
    bool ok = 1;
    for(int i = 0; i < 40; i ++) {
        if(cnt1[i] != cnt2[i]) {
            ok = 0;
            break ;
        }
    }
    if(ok == 0) {
        cout<<"NO\n";
        return ;
    }
    */
//    memset(vis, 0, sizeof vis);
    vector<pair<lli, lli> > ans;
    for(int i = 0; i < n; i ++ ) {
        if(s[i] == t[i]) {
            vis[i] = 1;
            continue ;
        }
        bool ok = 0;
        char srch = t[i];
        for(int j = i + 1; j < n; j ++) {
            if(srch == t[j]) {
                swap(s[i], t[j]);
                ok = 1;
                ans.push_back({i, j});
                break ;
            }
        }
        if(ok)
            continue ;
        for(int j = i + 1; j < n; j  ++ ) {
            if(srch == s[j]) {
                swap(s[j], t[j]);
                ans.push_back({j, j});
                swap(s[i], t[j]);
                ans.push_back({i, j});
                ok = 1;
                break ;
            }
        }
        if(ok == 0) {
            cout<<"NO\n";
            return ;
        }
    }
    if(ans.size() <= 2 * n){
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        for(auto it : ans)
            cout<<it.first + 1<<' '<<it.second + 1<<'\n';
    }
    else {
        cout<<"NO\n";
    }
//    cout<<'\n';
    return ;
}

/*
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}

