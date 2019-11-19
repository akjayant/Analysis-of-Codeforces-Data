#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FOR1(i, n) for(int (i)=1; (i)<=(n); (i)++)
#define FORI(i, n) for(int (i)=n-1; (i)>=0; (i)--)

int bf(int n, int m){
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, -1, 0, 1};

    int M = 1 << (n*m);
    int cnt = 0;
    FOR(mask, M){
        vector<vector<int>> a(n, vector<int>(m));
        FOR(i, n*m){
            if (mask & (1<<i)){
                int row = i/m;
                int col = i%m;
                a[row][col] = 1;
            }
        }

        bool good = 1;
        FOR(i, n){
            FOR(j, m){
//                cout << a[i][j];
                int cnt = 0;
                FOR(k, 4){
                    int i2 = i+di[k];
                    int j2 = j+dj[k];
                    if (i2 >=0 && i2 < n && j2 >=0 && j2 < m)
                        cnt += (a[i2][j2] == a[i][j]);
                }
                if (cnt>1)
                    good = 0;
            }
//            cout << endl;
        }
        if (good)
            cnt++;
//        cout << endl;
    }
    cout << cnt << endl;
    return cnt;
}

const ll MOD = 1e9+7;
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout << setprecision(15);
    if (argc == 2 && atoi(argv[1]) == 123456789) {
        freopen("d:\\code\\cpp\\contests\\stdin", "r", stdin);
        //freopen("d:\\code\\cpp\\contests\\stdout", "w", stdout);
    }

    int n = 1, m = 1;
    cin >> n >> m;
//    FOR1(n, 5)
//        FOR1(m, 5) {
//            cout << n << " " << m << " ";
//            bf(n, m);
//        }

    vector<ll> F(1e6+1);
    F[0] = 1; F[1] = 1;
    for(int i=2; i<=1e6; i++)
        F[i] = (F[i-1]+F[i-2])%MOD;

    cout << (2*(F[n]+F[m]+MOD-1))%MOD << endl;

    if (argc == 2 && atoi(argv[1]) == 123456789)        cerr << clock()*1.0/CLOCKS_PER_SEC << " sec\n";
    return 0;
}