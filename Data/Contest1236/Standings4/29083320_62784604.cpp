#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t,a,b,c,s=0;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        s=0;
        while(c>1 && b>0)
            c-=2, --b, ++s;
        while(a>0 && b>1)
            b-=2, --a, ++s;
        cout<<s*3<<"\n";
    }
    return 0;
}
