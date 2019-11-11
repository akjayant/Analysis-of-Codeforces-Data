#pragma GCC optimize ("2")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 2e5+5;
const int mxm = 1;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string s;

int check(){
    for(int i=0;i<s.size();i++){
        if(s[i]=='w'||s[i]=='m')return 0;
    }
    return 1;
}
int fib[mxn];
signed main(void){
    FAST_IO
    cin>>s;
    fib[1] = fib[0] = 1;
    fib[2] = 2;
    fib[3] = 3;
    for(int i=4;i<1e5+5;i++){
        fib[i] = fib[i-1]+fib[i-2];
        fib[i]%=mod;
    }

    if(check()==0){
        cout<<0;
        return 0;
    }
    int ans = 1,liann = 0,lianu = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='n'){
            liann++;
            ans = ans%mod * fib[lianu]%mod;
            ans%=mod;
            lianu=0;
        }
        else if(s[i]=='u'){
            lianu++;
            ans = ans%mod * fib[liann]%mod;
            ans%=mod;
            liann=0;
        }
        else{
            ans = ans%mod * fib[liann]%mod * fib[lianu]%mod;
            ans%=mod;
            liann=lianu=0;
        }
    }
    ans = ans%mod * fib[liann]%mod * fib[lianu]%mod;
    ans%=mod;
    liann = lianu = 0;
    cout<<ans<<endl;
    return 0;
}
