#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,b;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--){
        cin>>a>>b;
        if(__gcd(a,b)==1){
            cout<<"Finite"<<endl;
        }else{
            cout<<"Infinite"<<endl;
        }
    }
}