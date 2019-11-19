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

    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n%2 || count(s.begin(), s.end(), '(') != n/2){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    int mb = 0;
    pii sol(1, 1);
    FOR(i, n){
        FOR(j, n){
            swap(s[i], s[j]);
            int mv = n+1;
            int sum = 0;
            vector<int> ss(n);
            FOR(k, n){
                sum += s[k] == '(';
                sum -= s[k] == ')';
                ss[k] = sum;
                mv = min(mv, sum);
            }
            int cntm = 0;
            FOR(k, n)
                cntm += ss[k]==mv;
            if (cntm > mb){
                mb = cntm;
                sol = make_pair(i, j);
            }
            swap(s[i], s[j]);
        }
    }
    cout << mb << endl;
    cout << sol.first+1 << " " << sol.second+1 << endl;
//    swap(s[sol.first], s[sol.second]);
//    cout << s << endl;

    if (argc == 2 && atoi(argv[1]) == 123456789)        cerr << clock()*1.0/CLOCKS_PER_SEC << " sec\n";
    return 0;
}