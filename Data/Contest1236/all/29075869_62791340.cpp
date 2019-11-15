#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 305

using namespace std;
typedef long long ll;

int n;
int a[maxn][maxn];

int main(){
    BASE

    cin >> n;
    for (int j = 0, cnt = 0; j < n; ++j)
    for (int i = 0; i < n; ++i)
        if (j&1) a[n - i - 1][j] = ++cnt;
        else a[i][j] = ++cnt;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
