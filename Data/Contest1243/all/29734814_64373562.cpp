#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 100005
#define mod 2000003
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, x, y, i, t, a[N], j;
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> t;

    for(; t; t--) {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        sort(tot(a));

        for(i = n, j = 1; i >= 1; i--, j++) {
            if(a[i] < j)
                break;
        }

        cout << j - 1 << '\n';
    }

    return 0;
}
