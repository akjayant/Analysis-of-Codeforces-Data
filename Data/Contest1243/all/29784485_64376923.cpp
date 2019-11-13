#include<bits/stdc++.h>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;++a)
int test, n, a[100005];
main(){
    cin>>test;
    while(test--){
        cin>>n;
        For(i,1,n)cin>>a[i];
        sort(a+1,a+n+1);
        int ans=1;
        For(i,1,n){
            ans=max(ans,min(a[i],n-i+1));
        }
        cout<<ans<<'\n';
    }
}
