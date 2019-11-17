typedef long double ld;
using namespace std;


const long long mod = 1e9+7;



int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);




    string s;
    cin >> s;

    for(char c : s) {
        if(c == 'm' || c == 'w') {
            cout << 0 << "\n";
            exit(0);
        }
    }

    long long n = s.size() + 42;
    vector<long long> dp(n, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(long long i = 3; i < n; ++i)
        dp[i] = (dp[i-2] + dp[i-1]) % mod;

    vector<pair<char, long long>> a;
    for(long long i = 0; i < s.size(); ++i) {
        if(i == 0 || s[i] != a[a.size()-1].first) {
            a.push_back({s[i], 1});
        }
        else {
            a[a.size()-1].second++;
        }
    }

    long long res = 1;
    for(auto p : a) {
        if(p.first != 'n' && p.first != 'u') continue;
        res = (res * dp[p.second]) % mod;
    }

    cout << res << "\n";


    return 0;
}
