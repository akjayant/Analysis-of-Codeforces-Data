#include <bits/stdc++.h>
using namespace std;

#define INF             1e9
#define INFL            1e19
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

#define mid ((L+R)/2)
#define lchld (2*now)
#define rchld (2*now+1)

const int MAX = 1e5 + 2;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e5 + 2;
const int MOD = 1000000007;

int main()
{
//    READ;
    FASTIO;

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        while(b>0 and c>1){
            ans += 3;
            b--;
            c -= 2;
        }
        while(a>0 and b>1){
            ans += 3;
            a--;
            b -= 2;
        }
        cout << ans << "\n";
    }

    return 0;
}

