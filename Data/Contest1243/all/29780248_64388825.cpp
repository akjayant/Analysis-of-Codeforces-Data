#include <bits/stdc++.h>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("avx2")
//#pragma GCC target (sse, sse2, sse3, ssse3, sse4,popcnt,tune=native)

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define SZ(a) (int)(a.size())
#define Read() freopen("input.cpp", "r", stdin)
#define Write() freopen("output.cpp", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Unique(x)  x.erase(unique(all(x)), x.end())
#define pi acos(-1.0)
#define vec vector
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define endl "\n"
#define vec vector

using namespace std;

#define int long long

const int MAXN = 2e5 + 47, inf = 1e17 + 47;

int n, m;
vec<vec<int> >  graf(MAXN);

void read(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vec<int> alp(26, 0);
    loop(i, n) alp[a[i]-'a']++, alp[b[i] - 'a']++;
    loop(i, 26) if(alp[i] % 2 != 0) {
        cout << "No" << endl;
        return;
    }
/*
    vec<int> cnt(26, 0), many(26, 0) ,small(26, 0);
    loop(i, n) cnt[a[i] - 'a']++;
    loop(i, 26) {
        loop(j, alp[i] / 2 - cnt[i]) small[i]++;;
        loop(j, cnt[i] - alp[i] / 2) many[i]++;
    }

    vec<paii> per;
    loop(i, n) {
        if(small[a[i]-'a'] > 0) {
            loop(k, n) {
                if(many[b[k] -'a'] > 0) {
                    small[a[i]-'a']--, many[b[k]-'a']--;
                    swap(a[i], b[k]);
                    per.pb({i+1, k + 1});
                    break;
                }
            }
        } else if(many[a[i] - 'a'] > 0) {
            loop(k, n) {
                if(small[b[k]-'a'] >  0) {
                    small[b[i]-'a']--, many[a[i]-'a'];
                    swap(a[i], b[k]);
                    per.pb({i + 1, k + 1});
                    break;
                }
            }
        }
    }

    cout << a << " " << b << endl;*/

    vec<paii> per;
    loop(i, n) {
        if(a[i] != b[i]) {
            FOR(k, i + 1, n) {
                if(b[k] == a[i]) {
                    swap(b[k], a[i + 1]);
                    per.pb({i + 2, k + 1});
                    break;
                }
            }
            FOR(k, i + 1, n) {
                if(a[k] == a[i]) {
                    swap(b[i], a[k]);
                    per.pb({k + 1, i + 1});
                    break;
                }
            }
        }
    }

    cout << "Yes"<< endl;
    cout << SZ(per) << endl;
    loop(i, SZ(per)) cout << per[i].fr << " " << per[i].sc << endl;
}
void solve() {

}

signed main() {
    #ifdef COFFEE_MACHINE
        Read();
        Write();
    #endif
    CIN;
    int t = 1;
    cin >> t;
    while(t--) {
        read();
        solve();
    }
}/*
4
5
souse
houhe
3
car
dog
2
aa
az
3
abc
bca
*/
