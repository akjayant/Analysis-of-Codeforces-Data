#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

int arr[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for(int j = 1; j <= n; j++) {
                if(arr[j] >= i) cnt++;
            }
            if(cnt >= i) ans = max(ans, i);
        }
        cout << ans << '\n';
    }
}