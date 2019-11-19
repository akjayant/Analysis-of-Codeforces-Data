#include <bits/stdc++.h>
using namespace std;

#define INF             1e9
#define INFL            1e18
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cout << endl;
#define HOISE           cerr << "hoise" << endl
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << endl
#define READ            freopen("alu.txt", "r", stdin)
#define WRITE           freopen("vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)

#define MASK(x)         for(int i = 0; i < 8; i++){ if(x&(1<<i)){ cout << i << " "; } } cout << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e5 + 10;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e6 + 2;
const int MOD = 1000000007;

int main()
{
//    READ;
//    WRITE;
    FASTIO;

    ll n;
    cin >> n;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0)
                n /= i;

            if(n==1)
                cout << i;
            else
                cout << 1;

            return 0;
        }
    }
    cout << n;

    return 0;
}

/*
7 3 100
1 2 2
*/
