#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}

void ECHO(string _s){cout<<endl;(void)_s;}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i; string _s2="";
    for(_i=0;_i<sz(_s);++_i){if(_s[_i]==',')break;if(_s[_i]!=' ')_s2+=_s[_i];}
    if(_i==sz(_s)){--_i;}cout<<"  ("<<_s2<<"):"<<x;
    ECHO(_s.substr(_i+1, sz(_s)-_i-1), args...);
} 


template<typename T0, typename T1>
inline ostream& operator << (ostream& os, pair<T0, T1>& p){
    return os << "(" << p.first << ", " << p.second <<")";
}

template <typename T>
inline ostream& operator << (ostream& os, vector<T>& v){
    for(int i = 0; i < sz(v); ++i) {if(i > 0) cout << "_"; cout << v[i];} cout << endl;
    return os;
} 

//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

mt19937 ran(time(0));
const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;
const int int_inf = INT_MAX / 10;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

const ll MAX_N = 1e5 + 10;
ll c[3][MAX_N], dp[3][MAX_N], n;
int coloreo[MAX_N];
vector<vi> graph(MAX_N);
int depth[MAX_N];
vi estado(3);

void dfs(int u, int p, int dep) {
    depth[u] = dep;
    for(auto v : graph[u]) {
        if(v == p) continue;
        dfs(v, u, dep + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    ll i, a, b, uno = 0, dos = 1, tres = 2, m = inf, cont, root = 0;
    cin >> n;
    for(i = 0; i < n; i++) cin >> c[0][i];
    for(i = 0; i < n; i++) cin >> c[1][i];
    for(i = 0; i < n; i++) cin >> c[2][i];
    
    for(i = 0; i < n - 1; i++) {
        cin >> a >> b;
        --a; --b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    for(i = 0; i < n; i++) {
        if(graph[i].size() > 2) {
            cout << "-1\n";
            return 0;
        }
    }
    
    for(i = 0; i < n; i++) {
        if(graph[i].size() == 1) {
            root = i;
        }
    }
    
    dfs(root, -1, 0);
    //for(i = 0; i < n; i++) cout << depth[i] << " ";
    //cout << endl;
    estado[0] = 0;
    estado[1] = 1;
    estado[2] = 2;
    
    do{
        cont = 0;
        for(i = 0; i < n; i++) {
            cont += c[estado[depth[i]%3]][i];
        }
        if(cont < m) {
            m = cont;
            uno = estado[0];
            dos = estado[1];
            tres = estado[2];
        }
    
    } while(next_permutation(estado.begin(), estado.end()));
    
    estado[0] = uno;
    estado[1] = dos;
    estado[2] = tres;
    cout << m << "\n";
    for(i = 0; i < n; i++) {
        if(i > 0) cout << " ";
        cout << estado[depth[i]%3] + 1;
    }
    cout << "\n";

    return 0;
}



