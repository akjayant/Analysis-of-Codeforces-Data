#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;

int p[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string t;
    cin >> t;
    int ans = 0;
    int ui=0, uj = 0;
    int cnt = 0;
    for(int k = 0; k < n; k++) {
        if(t[k] == '(') cnt++;
    }
    if(2*cnt != n) {
        cout << 0 << endl;
        cout << 1 <<" " << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            swap(t[i], t[j]);
            int tmp = 0;
            int v = 0;
            int mmin = n+1;
            int p;
            for(int k = 0; k < n; k++) {
                if(t[k] == '(') v++;
                else v--;
                if(mmin > v) {
                    mmin = v;
                    p = k;
                }
            }
            string tt = t;
            for(int k = 0; k < n; k++) {
                tt[k] = t[(p+k+1)%n];
            }
            for(int k = 0; k < n; k++) {
                if(tt[k] == '(') v++;
                else v--;
                if(v==0) tmp++;
            }  
            if(ans < tmp) {
                ans = tmp;
                ui = i; uj = j;
            }
            swap(t[i], t[j]);
        }
    }
    //swap(t[ui], t[uj]);
    //cout << "debug " << t << endl;
    cout << ans << endl;
    cout << ui+1 << " " << uj+1 << endl;
    return 0;
}
