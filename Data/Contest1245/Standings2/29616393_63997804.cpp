#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

int t,a,b;

LL gcd(LL a,LL b){
        if(a>b){LL t=a;a=b;b=t;}
        if(!a) return b;
        while(b%a){LL t=a;a=b%a;b=t;}
        return a;
    }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(gcd(a,b)>1) cout<<"Infinite"<<endl;
        else cout<<"Finite"<<endl;
    }
    //system("pause");
    return 0;
}
