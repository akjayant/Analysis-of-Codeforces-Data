#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
bool is_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    bool bo=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            bo=0;
            ll m=n;
            while(m%i==0){
                m/=i;
            }
            if(m==1 && is_prime(i)){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    if(bo)cout<<n<<endl;
    else cout<<1<<endl;
}
