#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ll n,p;
    cin>>n;
    int c=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            p=i;
            c++;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(c==1){
        if(n==1) cout<<p<<"\n";
        else cout<<"1\n";
    }
    else if(c==0) cout<<n<<"\n";
    else cout<<"1\n";
    return 0;
}
