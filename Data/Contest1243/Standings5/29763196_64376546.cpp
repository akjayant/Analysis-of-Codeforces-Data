#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

int cnt[N];

int main() {
    //freopen("in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(cnt,0,sizeof cnt);
        for(int i = 0;i < n;++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for(int i = n;i >= 1;--i) {
            cnt[i] += cnt[i + 1];
            if(cnt[i] >= i) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}