#include<bits/stdc++.h>

using namespace std;

long long mod=1e9+7;

int main(){
        int n,m;
        cin>>n>>m;
        long long ans=0;
        long long e11=1,e00=1,e01=1,e10=1;
        for(int i=3;i<=n;i++){
                long long ne11=e01, ne00=e10, ne01=(e10+e00)%mod, ne10=(e01+e11)%mod;
                e11=ne11;e00=ne00;e01=ne01;e10=ne10;
        }
        long long str=(e11+e00+e01+e10)%mod;
        if(n==1)
                str=2;
        e11=1;e00=1;e01=1;e10=1;
        for(int i=3;i<=m;i++){
                long long ne11=e01, ne00=e10, ne01=(e10+e00)%mod, ne10=(e01+e11)%mod;
                e11=ne11;e00=ne00;e01=ne01;e10=ne10;
        }
        long long str2=(e11+e00+e01+e10)%mod;
        if(m==1)
                str2=2;
        cout<<(str+str2-2+mod)%mod;
}
