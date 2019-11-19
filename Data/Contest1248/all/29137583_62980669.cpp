/****************************/
/** Author : thantrongtri3 **/
/****************************/
#include <bits/stdc++.h>

using namespace std;

#define fuv(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define name ""

typedef pair<int, int> pii;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int INF = 1e9;
const int MOD = 1e9+7;
const int N = 1e5+10;

int s[2][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUGDE

    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                s[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            s[0][x%2]++;
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            s[1][x%2]++;
        }
        cout << 1LL*s[0][0]*s[1][0] + 1LL*s[0][1]*s[1][1] << "\n";
    }
    return 0;
}
