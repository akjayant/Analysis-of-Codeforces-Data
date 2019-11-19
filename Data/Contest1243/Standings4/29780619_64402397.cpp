#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define max(a,b) (a>b?a:b)
#define M 1000000007
#define N 1003
#define ll long long
#define f first
#define s second
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,x;
    cin>>n;
    x=n;
    for(i=2; i*i<=n; ++i){
        if(n%i==0){
            while(x%i==0)
                x/=i;
            if(x==1)
                cout<<i;
            else cout<<1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}