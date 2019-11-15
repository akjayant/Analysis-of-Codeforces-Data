#include <bits/stdc++.h>
using namespace std;
#define me(a, b) memset(a, b, sizeof(a))
#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int num[maxn];

int main()
{
    IOS();
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> num[i];
        sort(num, num+n);
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if(num[i] > ans) ans++;
            else break;
        }
        cout << ans << endl;
    }






    return 0;
}