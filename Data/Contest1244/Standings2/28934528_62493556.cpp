#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
int q;
ll l, p, a, b, k;
int main(){
    cin>>q;
    while(q--){
        cin>>l>>p>>a>>b>>k;
        ll x = l/a + (l%a!=0);
        ll y = p/b + (p%b!=0);
        if(x+y > k)
            cout<<"-1"<<endl;
        else cout<<x<<" "<<y<<endl;
    }
    return 0;
}