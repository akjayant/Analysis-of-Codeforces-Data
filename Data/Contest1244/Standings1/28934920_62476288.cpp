
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = int64_t;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n,p,w,d; cin >> n >> p >> w >> d;
    auto rest = p%w;
    ll low_d = -1;
    rep(i,w+1) {
        if((i*d)%w == rest) {
            low_d = i;
            break;
        }
    }
    auto min_p = low_d * d;
    auto rest_p = p - min_p;
    auto wins = rest_p / w;
    auto min_games = low_d + rest_p/w;

    if(low_d == -1 || rest_p < 0 || min_games > n) {
        cout << -1 << endl;
    } else
        cout << wins  <<' '<< low_d <<' '<<n-wins-low_d << endl;

    return 0;
}

