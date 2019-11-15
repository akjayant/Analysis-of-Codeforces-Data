#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll t,n,a[1005],vas;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n);
        vas=0;
        for(int i=n-1; i>=0; i--){
            if(a[i]<=n-i){
                vas=max(vas,a[i]);
                cout<<vas<<"\n";
                break;
            }
            else vas=n-i;
        }
    }
}
