#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define trav(a,b)   for(auto& a : (b))
#define debug(x)    clog << #x << " = " << x << endl;
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    int t; cin >> t;
    while (t--) {
        int n;cin >> n;
        string s; cin >> s;
        int lastOne = 0, firstOne = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                lastOne = max(lastOne, i);
                firstOne = min(firstOne, i);
            }
        }
        if (firstOne == n) {
            cout << n;
        } else {
            cout << max(2*(lastOne + 1), 2*(n-firstOne));
        }
        cout << endl;
    }


    cout.flush();
    return 0;
}

