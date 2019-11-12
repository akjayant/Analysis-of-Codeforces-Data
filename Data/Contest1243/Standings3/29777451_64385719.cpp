#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 10;
int a[maxn];
int n;

bool check(int pos){
    for(int i = 1; i <= n - pos + 1; i++) if(a[i] >= pos) return true;
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1; i <= n; i++) cin>>a[i];
        sort(a + 1, a + 1 + n);
        int l = 1, r = n;
        int ans;
        if(a[1] == a[n]){
            cout<<a[1]<<endl;
            continue;
        }
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) ans = mid, l = mid + 1;
            else r = mid;
        }
        cout<<ans<<endl;
    }
    return 0;
}
