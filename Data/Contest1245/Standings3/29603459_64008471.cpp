#include<bits/stdc++.h>

using namespace std;

int test, n;
int a[1010];
string s, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> test;
    while ( test-- ) {
        cin >> n >> a[1] >> a[2] >> a[3] >> s;
        res = "";
        for (int i = 0; i < n; i++) res += " ";
        for (int i = 0; i < n; i++) {
            if ( s[i] == 'R' && a[2] ) res[i] = 'P', a[2]--;
            if ( s[i] == 'P' && a[3] ) res[i] = 'S', a[3]--;
            if ( s[i] == 'S' && a[1] ) res[i] = 'R', a[1]--;
        }
        if ( 2 * (a[1] + a[2] + a[3]) > n ) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if ( res[i] == ' ' ) {
                    if ( a[1] ) res[i] = 'R', a[1]--;
                    else if ( a[2] ) res[i] = 'P', a[2]--;
                        else if ( a[3] ) res[i] = 'S', a[3]--;
                }
            }
            cout << res << "\n";
        }
    }

    return 0;
}
