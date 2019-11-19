#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;

int a[maxN];
int b[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        LL ncnt0=0, ncnt1=0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 0) ncnt0++; 
            else ncnt1++;
        }

        int m; cin >> m;
        LL mcnt0=0, mcnt1=0;
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            if(b[i] % 2 == 0) mcnt0++; 
            else mcnt1++;
        }

        cout << ncnt0*mcnt0 + ncnt1*mcnt1 << endl;
    }

    return 0;
}
