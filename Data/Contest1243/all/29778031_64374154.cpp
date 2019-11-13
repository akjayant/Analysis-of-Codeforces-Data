#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
const int N = int(5e5) + 12, mod = int(1e9)  + 7;
int a[N];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int q = n; q>= 1;q--) {
            int cnt = 0;
            for(int j=1;j<=n;j++) {
                if(a[j] >= q)
                    cnt++;
            }
            if(cnt >= q) {
                cout<<q<<endl;
                break;
            }
        }
    }
}
/*
 5 5 6
 1 2 3 4 5
 1 2 1 1
 2 3 1 3
 4 2 4 4
 2 5 1 4
 3 2 2 3
 3 2 3 3
 */
