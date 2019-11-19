#include<bits/stdc++.h>
#define IO cin.tie(0);ios_base::sync_with_stdio(false);
#define endl '\n'
#define int long long
using namespace std;

signed main(){
    IO
    int n,a,b,p0,p1,q0,q1,t;
    cin>>t;
    while(t--){
        p0=0;p1=0;q0=0;q1=0;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a;
            if(a%2)p1++;
            else p0++;
        }
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a;
            if(a%2)q1++;
            else q0++;
        }
        cout<<(p0*q0)+(p1*q1)<<endl;
    }
    return 0;
}
