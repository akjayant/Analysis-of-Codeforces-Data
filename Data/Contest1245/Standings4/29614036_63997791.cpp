#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define pll pair<long long, long long>
#define pt complex<double>
#define ft first
#define sc second
using namespace std;

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int main(){
    int t;
    ll a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(gcd(a, b) == 1){
            cout<<"Finite"<<endl;
        }
        else{
            cout<<"Infinite"<<endl;
        }
    }
}
