#include<bits/stdc++.h>
using namespace std;

typedef long double                 ld;
typedef long long                   ll;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define F                           first
#define S                           second
#define sep                         ' '
#define endl                        '\n'
#define file_io                     freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define error(x)                    cerr << "$$$ " << x << '\n';
#define error2(x,y)                 cerr << "#F : " << x << "      #S : " << y << '\n';
#define kill(x)                     return cout << x << endl , 0;
#define pb                          push_back

const ll MXN = 1e3 + 10;
const ll MXM = 5e2 + 10;
const ll MX5 = 1e5 + 10;
const ll MX6 = 1e6 + 10;
const ll INF = 8e18;
const ld eps = 1e-9;
const ll MOD = 1e9 + 7; //998244353;

ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
ll bmm(ll a,ll b){
    return (a%b==0 ? b : bmm(b,a%b));
}
string base2(ll n){
    string a="";while(n>=2){a+=(char)(n%2+'0');n/=2;}a+=(char)(n+'0');reverse(all(a));return a;
}

ll A[MX5];
ll mr1[200], mr2[200], Ch[200];
vector<ll> v;
bool vis[100];
vector<pll> Ans;

int solve(){
    ll n, ans = 0;
    cin >> n;
    string s, t;
    cin >> s >> t;
    fill(mr1, mr1 + 140, 0);
    fill(mr2, mr2 + 140, 0);
    fill(vis, vis + 70, 0);
    fill(Ch, Ch + 150, 0);
    v.clear();
    Ans.clear();
    for(int i = 0; i < n; i++) mr1[s[i]]++;
    for(int i = 0; i < n; i++) mr2[t[i]]++;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            ans++;
            vis[i] = 1;
            v.pb(i);
            Ch[s[i]]++;
            Ch[t[i]]++;
        }
    }
    for(int i = 'a'; i <= 'z'; i++){
        if(Ch[i] % 2 == 1){
            kill("NO");
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) continue;
        bool f = 0, found = 0;
        for(int j = i + 1; j < n; j++){
            if(s[j] == t[j]) continue;
            if(s[j] == s[i]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            bool flag = 0;
            ll ind;
            for(int j = i + 1; j < n; j++){
                if(s[j] == t[j]) continue;
                if(t[j] == s[i]){
                    ind = j;
                    flag = 1;
                    break;
                }
            }

            if(!flag){
                kill("NO");
            }
            bool ff = 0;
            for(int j = i + 1; j < n; j++){
                if(s[j] == t[j]) continue;
                if(t[i] == t[j]){
                    Ans.pb({j, ind});
                    swap(s[j], t[ind]);
                    ff = 1;
                    break;
                }
            }
            if(!ff){
                for(int j = i + 1; j < n; j++){
                    if(s[j] == t[j]) continue;

                    Ans.pb({j, ind});
                    swap(s[j], t[ind]);
                    ff = 1;
                    break;

                }
            }
            if(!ff){
                kill("NO");
            }
        }
        for(int j = i + 1; j < n; j++){
            if(s[j] == t[j]) continue;
            if(s[j] == s[i] && t[j] == t[i]){
                Ans.pb({j, i});
                swap(s[j], t[i]);
                f = 1;
                break;
            }
        }
        if(!f){
            for(int j = i + 1; j < n; j++){
                if(s[j] == t[j]) continue;
                if(s[j] == s[i]){
                    Ans.pb({j, i});
                    f = 1;
                    swap(s[j], t[i]);
                    break;
                }
            }
        }
        if(!f){
            kill("NO");
        }
    }
    if(Ans.size() <= 2 * n){
        cout << "YES" << endl;
        cout << Ans.size() << endl;
        for(int h = 0; h < Ans.size(); h++){
            cout << Ans[h].F + 1 << sep << Ans[h].S + 1 << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
int main(){
    //fast_io
    //file_io
    ll q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
//! N.N
