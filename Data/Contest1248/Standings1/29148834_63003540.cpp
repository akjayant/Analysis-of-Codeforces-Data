#include <bits/stdc++.h>
 
#define loop(i, n) for(ll i = 0; i < n; i++)
#define loop1(i, a, n) for(int i = a; i < n; i++)
#define PI 3.141592653589793238
#define bc __builtin_popcountll
#define pf push_front
#define pb push_back
#define rf pop_front
#define rb pop_back
#define fs first
#define sc second
#define mp make_pair
#define fi ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9 + 7;
const ll INF = 1e9;
inline ll pwr(ll base, ll n, ll m) {ll ans = 1;while( n > 0 ) {if ( n & 1 ) ans = (ans * base) % m; base = (base * base) % m; n>>=1;}return ans;}

const int N = 1e5 + 10;
string s;
int n, cumm_cnt[N];

int count_blocks() {
    int cnt = 0, c = 0, mx = 0, pos = 0;

    loop(i, n) {
        cumm_cnt[i] = 0;
        if( s[i] == '(') cumm_cnt[i]++;
        else cumm_cnt[i]--;
        
        if(i) cumm_cnt[i] += cumm_cnt[i-1];

        if( cumm_cnt[i] < 0 && mx >= cumm_cnt[i] ) {
            mx = cumm_cnt[i];
            pos = i;
        }
        if( cumm_cnt[i] == 0 ) cnt++;
    }

    if( cumm_cnt[n-1] != 0 )
        return -1;
    if( mx == 0 )
        return cnt;

    int j = n-1, st = -1;
    c = 0;

    while( j > pos ) {
        if( s[j] == '(') c++;
        else c--;

        if( c == abs(mx)) {
            if( j-pos == 1 || cumm_cnt[j-1] - cumm_cnt[pos] == 0) {
                st = j;
                break;
            }
        }

        j--;
    }

    if( st == -1 ) return -1;
    cnt = 0;
    c = 0;

    loop1(i, st, n) {
        if( s[i] == '(') c++;
        else c--;
        if( c == 0 ) cnt++;
    }
    loop(i, st) {
        if( s[i] == '(') c++;
        else c--;
        if( c == 0 ) cnt++;        
    }
    return cnt;
}

int main() {
    fi;

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    #endif

    cin >> n;
    cin >> s;

    int ans = 0, x = 1, y = 1;

    loop(i, n) {
        loop1(j, i, n) {
            swap(s[i], s[j]);
            int cnt = count_blocks();

            if( cnt >= ans ) {
                ans = cnt;
                x = i+1;
                y = j+1;
            }
            swap(s[i], s[j]);
        }
    }

    cout << ans << "\n";
    cout << x << " " << y;

    return 0;
}