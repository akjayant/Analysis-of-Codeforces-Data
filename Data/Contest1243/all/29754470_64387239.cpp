#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10, mod=1e9+7;
long long n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    vector<long long> v;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(i*i!=n) v.push_back(n/i);
        }
    }
    long long g=0;
    for(long long x:v) g=__gcd(g,x);
    if(g) cout<<g<<'\n';
    else cout<<n<<'\n';
    return 0;
}
