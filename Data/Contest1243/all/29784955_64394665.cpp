#include<bits/stdc++.h>

using namespace std;
const int N = 1234;
typedef long long ll;

int main(){

    ll n;

    cin>>n;
    ll nn = n;
    set<ll> div;
    for(ll i =2; i*i <= n; i++){
        if(n%i==0) div.insert(i);
        while(n%i==0) n/=i;
    }

    if(n!=1){
        div.insert(n);
    }
    if(div.size()==1){
        cout<<(*(div.begin()))<<endl;
    } else {
        cout<<"1\n";
    }
    return 0;
}


