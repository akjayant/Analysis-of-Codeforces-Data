#include "bits/stdc++.h"
using namespace std;

int n,a[1111];

bool ok(int x) {
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(a[i]>=x) cnt++;
        if(cnt==x) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int ans;
        for(int i=n;i;i--) {
            if(ok(i)) {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
