#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int n,m;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,t,ans=0;
        cin>>a>>b>>c;
        t = c/2;
        if(b<t)
            t = b;
        ans += (3*t);
        b-=t;
        t = b/2;
        if(a<t)
            t = a;
        ans += (3*t);
        cout<<ans<<endl;
    }
    return 0;
}