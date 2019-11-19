#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100,delta=1e9+7;

void calc(){
    long long n;
    cin>>n;
    long long f1=0,z1=0;
    while(n--){
        long long t;
        cin>>t;
        if(max(t,-t)%2==1)f1++;
        else z1++;
    }
    cin>>n;
    long long f2=0,z2=0;
    while(n--){
        long long t;
        cin>>t;
        if(max(t,-t)%2==1)f2++;
        else z2++;
    }
    long long ans=z2*z1+f1*f2;
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long q;
    cin>>q;
    while(q--)calc();
}
