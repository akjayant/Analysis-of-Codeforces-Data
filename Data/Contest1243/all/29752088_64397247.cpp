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
        string s, t;
        cin >> n;
        cin >> s >> t;

        vector<int> c(26, 0);
        for(int i = 0; i < n; i++){
            c[s[i]-'a']++;
            c[t[i]-'a']++;
        }

        bool ok = true;
        for(int i = 0; i < 26; i++)
            if(c[i]%2==1)
                ok = false;

        if(!ok){
            cout << "No\n";
            continue;
        }

        vector<pii> ans;
        for(int i = 0; i < n; i++){
            if(s[i]!=t[i]){
                bool swaped = false;
                for(int j = i+1; j < n; j++){
                    if(t[j]==s[i]){
                        ans.PB({j,j});
                        ans.PB({j,i});
                        swap(s[j], t[j]);
                        swap(s[j], t[i]);
                        swaped = true;
                        break;
                    }
                }
                if(!swaped){
                    for(int j = i+1; j < n; j++){
                        if(s[j]==s[i]){
                            swap(s[j], t[i]);
                            ans.PB({j, i});
                            swaped = true;
                            break;
                        }
                    }
                }
            }
//            DEBUG(s);
//            DEBUG(t);
        }

        cout << "Yes\n";
        cout << (int)ans.size() << "\n";
        for(pii p: ans)
            cout << p.XX+1 << " " << p.YY+1 << "\n";
    }

    return 0;
}

/*
1
5
souse
houhe
*/
