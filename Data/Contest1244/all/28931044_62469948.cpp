#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 100005
#define mod 2000003
#define oo 1000000007
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int t, T, n, a, b, c, d, k, x, y, i, j;
string s;
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> t;

    for(; t; t--) {
        cin >> n;
        cin >> s;

        for(i = 0; i < n; i++)
            if(s[i] == '1')
                break;

        x = i;

        for(i = n - 1, j = 0; i >= 0; i--, j++)
            if(s[i] == '1')
                break;

        if(x == n) {
            cout << n << "\n";
            continue;
        }

        cout << max((n - x), (n - j)) * 2 << "\n";;
    }

    return 0;
}


