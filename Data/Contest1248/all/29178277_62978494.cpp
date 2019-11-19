#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FOR1(i, n) for(int (i)=1; (i)<=(n); (i)++)
#define FORI(i, n) for(int (i)=n-1; (i)>=0; (i)--)

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout << setprecision(15);
    if (argc == 2 && atoi(argv[1]) == 123456789) {
        freopen("d:\\code\\cpp\\contests\\stdin", "r", stdin);
        //freopen("d:\\code\\cpp\\contests\\stdout", "w", stdout);
    }

    int T;
    cin >> T;
    FOR(t, T){
        int n;
        cin >> n;
        vector<int> p(n);
        vector<ll> pm(2);
        FOR(i, n) {
            cin >> p[i];
            pm[p[i]%2]++;
        }

        int m;
        cin >> m;
        vector<int> q(m);
        vector<ll> qm(2);
        FOR(i, m) {
            cin >> q[i];
            qm[q[i]%2]++;
        }

        ll sol = 0;
        FOR(i, 2){
            sol += pm[i] * qm[i];
        }
        cout << sol << endl;
    }


    if (argc == 2 && atoi(argv[1]) == 123456789)        cerr << clock()*1.0/CLOCKS_PER_SEC << " sec\n";
    return 0;
}