#include <bits/stdc++.h>

#pragma GCC optimize("O3")

#define f first
#define s second
#define p push
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

const int N = 2e5 + 2, inf = 1e9 + 10;

int a[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    for(int t = 0; t < q; ++t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int minp = inf, maxp = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] - '0')
                minp = min(minp, i), maxp = max(maxp, i);
        }
        if(maxp == -1 && minp == inf){
            cout << n << "\n";
        }else
            cout << max(maxp + 1, n - minp) * 2 << "\n";
    }

}
