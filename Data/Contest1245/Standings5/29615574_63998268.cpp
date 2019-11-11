#include<bits/stdc++.h>
using namespace std;
int test,a,b;
int main() {
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    cin>>test;
    while(test--) {
        cin>>a>>b;
        int u=__gcd(a,b);
        if(u==1) {
            cout<<"Finite"<<endl;
        }
        else cout<<"Infinite"<<endl;
    }
}
