#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mpr make_pair
#define mt make_tuple
 
using namespace std;
 
const int N = 100000;
const int mod = 1e9 + 7;
ll power(ll x, ll y, ll p){ ll res = 1; x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;} return res; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b,c,res;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        res = 0;
        if(c/2 >= b){
            res += 3*b;
            b = 0;
        }
        else{
            res += 3*(c/2);
            b -= c/2;
        }
        if(b/2 >= a){
            res += 3*a;
            a = 0;
        }
        else{
            res += 3*(b/2);
            a -= b/2;
        }
        cout<<res<<endl;
    }
    return 0;
}