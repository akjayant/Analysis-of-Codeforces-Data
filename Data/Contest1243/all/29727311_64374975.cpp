#include <bits/stdc++.h>
 
using namespace std;

int f[2000];

int main(){
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >>n;
        for (int i=0; i<2000; ++i){
            f[i] = 0;
        }
        for (int i=0; i<n; ++i){
            int a;
            cin >>a;
            f[a]++;
        }
        int cnt = 0;
        int ans = 0;
        for (int i=1; i<2000; ++i){
            if (n - cnt >= i){
                ans = max(ans, i);
            }
            cnt += f[i];
        }
        cout <<ans <<'\n';
    }
    return 0;
}
