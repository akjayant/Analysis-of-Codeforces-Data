#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")


int main(){
    int t;
    cin>>t;
    for(;t;t--){
        int a,b;
        cin>>a>>b;
        cout<<(__gcd(a,b)==1?"Finite":"Infinite")<<endl;
    }
}