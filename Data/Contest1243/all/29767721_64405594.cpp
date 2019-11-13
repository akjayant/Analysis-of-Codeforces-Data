// <copy-paste>
#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define eb push_back
#define MAXN 1000009
#define MOD 1000000007
#define mp(x, y) make_pair(x,y)
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define pll pair <ll,ll>
using namespace std;

typedef unsigned long long LLU;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
const bool print=false;
typedef long long ll;

template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int const N = 1e5 + 9;
int const maxn = 1e6 + 9;

ll n,m,k;

vector<int> adj[MAXN];

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int c[MAXN];
string s, t;
vector<PII> ans;
int solve(){
    memset(c, 0, sizeof c);
    bool ok = 0;
    int n;
    cin >> n >> s >> t;
    int cnt = 0;
    vector <int> q;
    for(int i = 0; i < n; i ++)
        if(s[i] != t[i]){
            q.push_back(i);
            c[s[i] - 'a'] ++;
            c[t[i] - 'a'] ++;

        }
    for(int i = 0; i < 26; i ++)
        if(c[i] & 1)
            return cout << "No\n", 0;
    for(int i = 0 ; i < n  - 1 ; i ++){
        if ( s[i] == t[i] ) continue;
        int flag = 0;
        for(int j = i + 1; j < n ; j++){
            if ( s[j] == s[i] ){
                swap(s[j],t[i]);
                ans.push_back(make_pair(j,i));
                flag = 1;
                break;
            }
        }
        if ( !flag ){
            for ( int j = i + 1; j < n ; j++){
                if ( t[j] == s[i] ){
                    int ok = 0;
                    for ( int h = i + 1 ; h < n ; h ++){
                        if ( s[h] == s[j] && h != j ){
                            swap(s[h],t[j]);
                            ans.push_back(make_pair(h,j));
                            swap(s[h],t[i]);
                            ans.push_back(make_pair(h,i));
                            ok = 1;
                            break;
                        }
                    }
                    if ( !ok ){
                        swap(t[j],s[i+1]);
                        ans.push_back(make_pair(i+1,j));
                        swap(s[i+1],t[i]);
                        ans.push_back(make_pair(i+1,i));
                    }
                    break;
                }
            }
        }

    }
    if ( ans.size() <= 2*n ){
        cout << "Yes" << endl << ans.size() << endl;
        for ( auto x : ans){
            cout << x.first + 1<< ' ' << x.second + 1<< endl;
        }
    }
    else cout << "No" << endl;
    ans.clear();
}
int main()
{
    FAST;
    int t=1;
//    scanf("%d", &t);
    cin >> t;
    while(t --){
        solve();
    }
}
//</copy-paste>
