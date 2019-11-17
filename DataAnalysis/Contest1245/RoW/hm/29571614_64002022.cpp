
using namespace std;




typedef long long vlong;


const vlong mod = 1000000007;
vlong dp[200005];
string s;
int n;

vlong f(int pos) {

    vlong &res = dp[pos];
    if(res != -1) return res;

    if(pos == n) {
        return res = 1;
    }

    res = 0;
    vlong tmp;

    res = f(pos+1);

    if(pos < n-1) {
        if(s[pos] == 'u' || s[pos] == 'n') {
            if(s[pos] == s[pos+1]) {
                tmp = f(pos+2);
                res = (res + tmp) % mod;
            }
        }
    }

    return res;
}


int main () {





    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> s;
    n = ((vlong)(s).size());

    for(vlong i = (0) ; i <= (n-1) ; ++i) {
        if(s[i] == 'm' || s[i] == 'w') {
            cout << 0 << "\n";
            return 0;
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << f(0) << "\n";

    return 0;
}
