#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    int n, t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        if(__gcd(a, b)==1){
            cout<<"Finite"<<endl;
        }
        else{
            cout<<"Infinite"<<endl;
        }
    }
  return 0;
}


