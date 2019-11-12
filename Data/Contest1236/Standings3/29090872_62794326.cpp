#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, i, j;
    int a[302][302];
    cin >> n;
    int cur = 1;
    for(i = 0; i < n; i++) {
        if(i % 2) {
            j = n - 1;
            while(j >= 0) {
                a[i][j--] = cur++;
            }
        }
        else {
            j = 0;
            while(j < n) {
                a[i][j++] = cur++;
            }
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}