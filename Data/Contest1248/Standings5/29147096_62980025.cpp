#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int m;
        cin>>m;
        lli even=0,odd=0;
        for(int i=0;i<m;i++){
            lli x;
            cin>>x;
            if(x%2==0)even++;
            else odd++;
        }
        lli ans = 0;
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                ans+=even;
            }else{
                ans+=odd;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
