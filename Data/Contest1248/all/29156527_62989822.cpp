#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;

int a[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    LL sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    LL row = 0;
    for(int i = 0; i < n/2; i++) {
        row += a[i]; 
    }
    LL col = sum - row;
    cout << row * row + col * col << endl;

    return 0;
}
