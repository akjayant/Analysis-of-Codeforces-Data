#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

#define fo(i,a,z) for(ll i=(a);i<(z);++i)
#define MAX 100005

ll t, n, a, b, c, ans;

int main() {
    cin >> t;
    fo(_t,0,t) {
        map<ll,ll> counts;
        string s, out;
        ll score = 0;
        cin >> n >> a >> b >> c >> s;
        fo(i,0,n) {
            switch (s[i]) {
            case 'R':
                if (b > 0) { --b; ++score; out.push_back('P'); }
                else out.push_back('.');
                break;
            case 'P':
                if (c > 0) { --c; ++score; out.push_back('S'); }
                else out.push_back('.');
                break;
            case 'S':
                if (a > 0) { --a; ++score; out.push_back('R'); }
                else out.push_back('.');
                break;
            }
        }
        fo(i,0,n) {
            if (out[i] == '.') {
                if(a) --a, out[i]='R';
                else if(b) --b, out[i]='P';
                else if(c) --c, out[i]='S';
            }
        }
        if (score >= (n+1)/2) {
            cout << "YES\n" << out << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
