#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a,b,c,cnt = 0;
    cin >> a >> b >> c;
    string s,ans;
    ans.resize(n,'*');
    cin >> s;
    for(int i = 0;i < s.size(); ++i){
        if(s[i] == 'R' && b > 0){
            --b;
            ans[i] = 'P';
            cnt++;
        }
        if(s[i] == 'P' && c > 0){
            --c;
            ans[i] = 'S';
            cnt++;
        }
        if(s[i] == 'S' && a > 0){
            --a;
            ans[i] = 'R';
            cnt++;
        }
    }
    for(int i = 0;i < s.size(); ++i){
        if(ans[i] == '*'){
            if(a > 0){ans[i] = 'R',--a;}else
            if(b > 0){ans[i] = 'P',--b;}else
            if(c > 0){ans[i] = 'S',--c;}
        }
    }
    int cmp = n / 2;
    if(n % 2)cmp++;
    if(cnt >= cmp){
        cout << "YES\n";
        cout << ans;
    }else{
        cout << "NO";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0;i < t; ++i){
        solve();
        cout << "\n";
    }
    return 0;
}
