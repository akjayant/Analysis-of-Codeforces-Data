/**
*    author:  a2954898606
*    created: 2019/10/17 21:25:20
**/
/*
ЗАПУСКАЕМ
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░
 */
#include<bits/stdc++.h>
#define REP(A,B,I) for(int I=(A);I<=(B);I++)
#define PER(A,B,I) for(int I=(A);I>=(B);I--)
#define LL long long
#define N 1000010
#define M 100
using namespace std;
const long long mod=1e9+7;
//long long quickpow(long long a,long long b){long long ret=1;while(b){if(b&1){ret=ret*a%mod;}}a=a*a%mod;b>>=1;return ret;}
long long quickpow(long long a,long long b){
    long long ret=1;
    while(b){
        if(b&1){
            ret=ret*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
//using namespace std;
long long n,m,ans;
int main(){

    cin>>n>>m;
    ans=quickpow(2,m);
    ans--;
    ans=quickpow(ans,n);
    cout<<ans<<endl;
    return 0;
}
