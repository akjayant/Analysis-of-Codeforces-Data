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

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        bool done = false;
        int ans = 0;
        for(int i = 1000; i >= 0 and !done; i--){
            int cnt = 0;
            for(int j = 0; j < n; j++)
                cnt += (a[j]>=i);

            if(cnt>=i){
                ans = i;
                done = true;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

/*
7 3 100
1 2 2
*/
