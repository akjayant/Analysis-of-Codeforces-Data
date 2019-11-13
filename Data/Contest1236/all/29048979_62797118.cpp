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

const int MAX = 300 + 2;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e5 + 2;
const int MOD = 1e9 + 7;

vector<int> a[MAX];

int main()
{
//    READ;
    FASTIO;

    int n, x = 1, i = 1;
    cin >> n;
    int lmt = n*n;
    int inc = 1;
    while(x <= lmt){
        a[i].PB(x);
        x++;
        i += inc;
        if(i > n) inc = -1, i = n;
        if(i < 1) inc = +1, i = 1;
    }

    for(i = 1; i <= n; i++){
        for(int y: a[i])
            cout << y << " ";
        cout << "\n";
    }

    return 0;
}

