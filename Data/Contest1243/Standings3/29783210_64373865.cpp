#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;

int arr[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, arr + n, greater<int>());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, min(i + 1, arr[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
