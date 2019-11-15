#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

int T, n;
string s, t;
vector<pii> ans;

void print(){
    puts("Yes");
    printf("%d\n", ans.size());
    for(pii i : ans)
        printf("%d %d\n", i.ff, i.ss);
}

int main()
{
    cin >> T;
    while(T--){
        ans.clear();
        cin >> n >> s >> t;
        for(int i = 0; i < n; i++){
            if(s[i] == t[i])
                continue;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    swap(t[i], s[j]);
                    ans.pb({j + 1, i + 1});
                    break;
                }
            }
            if(s[i] == t[i])
                continue;
            for(int j = i + 1; j < n; j++){
                if(s[i] == t[j]){
                    swap(s[n - 1], t[j]);
                    ans.pb({n, j + 1});
                    swap(t[i], s[n - 1]);
                    ans.pb({n, i + 1});
                    break;
                }
            }
        }
        if(s == t)
            print();
        else
            puts("No");
    }

    return 0;
}
