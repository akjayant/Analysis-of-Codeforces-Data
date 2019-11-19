#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,m,i;
    cin>>n>>m;
    vector<long long int> f(max(m,n)+1,0);
    f[0]=1;
    f[1]=1;
    for (i=2; i<max(m,n)+1; i++){
        f[i]=(f[i-2]+f[i-1])%1000000007;
    }
    cout<<(2*(f[n]+f[m])-2)%1000000007;
    return 0;
}
