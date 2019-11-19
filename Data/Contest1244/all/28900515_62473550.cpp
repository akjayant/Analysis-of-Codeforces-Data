#include<bits/stdc++.h>
#define rep(i,b,e) for(int i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

int t,n;char c;int a[1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;int ans=n;
        rep(i,1,n+1){
            cin>>c;
            a[i]=c-'0';
            if(a[i]) ans=max(ans,max(2*i,2*n-2*i+2));
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
