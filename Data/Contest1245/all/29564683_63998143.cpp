#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        int g=__gcd(a,b);
        if(g==1){
            cout<<"Finite"<<endl;
        }
        else cout<<"Infinite"<<endl;
    }

}