#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[1003]={};
        for(int i=0;i<n;++i) {
            int tmp;
            cin >> tmp;
            ++a[tmp];
        }
        for(int i=n;i>=0;--i)
            a[i]+=a[i+1];
        int ans=1;
        for(int i=0;i<=n;++i)
            if(a[i]>=i)
                ans=max(ans,i);
        cout << ans << endl;
    }

}
