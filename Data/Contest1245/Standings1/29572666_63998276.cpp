#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        cout<<(gcd(a,b)==1?"Finite\n":"Infinite\n");
    }
}