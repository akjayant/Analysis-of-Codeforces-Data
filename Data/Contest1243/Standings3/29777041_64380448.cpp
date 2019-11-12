#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1,greater<int>());
        int i;
        for (i=1;i<=n;i++){
            if(i>a[i]){
                i--;
                break;
            }
        }
        if(i==n+1) cout << i-1 << endl;
        else cout << i << endl;
    }
    return 0;
}
