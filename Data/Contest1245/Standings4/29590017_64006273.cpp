//⣿⣿⣿⣿⣿⣿⠟⠋⠁⣀⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿
//⣿⣿⣿⣿⠋⠁⠀⠀⠺⠿⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⣿
//⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⠀⠀⠀⠀⠀⣤⣦⣄⠀⠀
//⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⠏⣿⣿⣿⣿⣿⣁⠀⠀⠀⠛⠙⠛⠋⠀⠀
//⡿⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⣰⣿⣿⣿⣿⡄⠘⣿⣿⣿⣿⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀
//⡇⠀⠀⠀⠀⠀⠀⠀⠸⠇⣼⣿⣿⣿⣿⣿⣷⣄⠘⢿⣿⣿⣿⣅⠀⠀⠀⠀⠀⠀⠀⠀
//⠁⠀⠀⠀⣴⣿⠀⣐⣣⣸⣿⣿⣿⣿⣿⠟⠛⠛⠀⠌⠻⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣶⣮⣽⣰⣿⡿⢿⣿⣿⣿⣿⣿⡀⢿⣤⠄⢠⣄⢹⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣿⣿⣿⣿⣿⡘⣿⣿⣿⣿⣿⣿⠿⣶⣶⣾⣿⣿⡆⢻⣿⣿⠃⢠⠖⠛⣛⣷⠀
//⠀⠀⢸⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣮⣝⡻⠿⠿⢃⣄⣭⡟⢀⡎⣰⡶⣪⣿⠀
//⠀⠀⠘⣿⣿⣿⠟⣛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⡿⢁⣾⣿⢿⣿⣿⠏⠀
//⠀⠀⠀⣻⣿⡟⠘⠿⠿⠎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣿⣿⠧⣷⠟⠁⠀⠀
//⡇⠀⠀⢹⣿⡧⠀⡀⠀⣀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⢰⣿⠀⠀⠀⠀
//⡇⠀⠀⠀⢻⢰⣿⣶⣿⡿⠿⢂⣿⣿⣿⣿⣿⣿⣿⢿⣻⣿⣿⣿⡏⠀⠀⠁⠀⠀⠀⠀
//⣷⠀⠀⠀⠀⠈⠿⠟⣁⣴⣾⣿⣿⠿⠿⣛⣋⣥⣶⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⣿ 
//⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//⣿⠛⣷⠀⠀⢸⣟⡛⠀⠀⣿⠛⣷⠀⠀⢸⣟⡛⠀⠀⣴⢟⣛⡀⠀⠀⣸⢿⣇⠀ 
//⣿⠉⠉⠀⠀⢸⣯⣥⠀⠀⣿⠉⠉⠀⠀⢸⣯⣥⠀⠀⢿⣮⣽⡇⠀⢠⡿⠶⣿⡄ 
#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 300309
#define MAXM 900009
#define MAXLOGN 20
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define pr printf
#define sc(x) scanf("%d", &x)
#define sc2(x, y) sc(x);sc(y)
#define sc3(x, y, z) sc2(x, y);sc(z)
#define scll(x) scanf("%lld", &x)
#define sc2ll(x, y) scll(x);scll(y)
#define sc3ll(x, y, z) sc2ll(x, y);scll(z)
#define ff first
#define ss second
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x))
#define LOWBIT(A) (A & -A)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair <ll, ll> pll;
typedef pair < pll, ll > plll;

ll multi(ll a, ll b){
    return (a * b)%MOD;
}

ll addi(ll a, ll b){
    return (a + b)%MOD;
}

ll resp;
ll fibo[100010];

void calculate(ll qtd, ll tipo){
    if(tipo == -1)return;
    resp = multi(resp, fibo[qtd]);
}

int main() {
    string s;
    cin >> s;
    resp = 1;
    fibo[0] = fibo[1] = 1;
    fibo[2] = 2;
    FOR(i, 100010) {if(i < 3)continue;else fibo[i] = addi(fibo[i - 1], fibo[i - 2]);}
    ll qtd = 0;
    ll tipo = -1;
    FOR(i, sz(s)){
        if(s[i] == 'm' || s[i] == 'w')resp *= 0;
        else if(s[i] == 'n'){
            if(tipo == 1){
                qtd++;
            }else{
                calculate(qtd, tipo);
                tipo = 1;
                qtd = 1;
            }
        }else if(s[i] == 'u'){
            if(tipo == 2){
                qtd++;
            }else{
                calculate(qtd, tipo);
                tipo = 2;
                qtd = 1;
            }
        }else{
            calculate(qtd, tipo);
            tipo = -1;
            qtd = 0;
        }
    }
    calculate(qtd, tipo);
    pr("%lld\n", resp);
    return 0;
} 
