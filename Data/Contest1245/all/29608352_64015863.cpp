#include <bits/stdc++.h>
using namespace std;



int flagn = 0, flagu = 0, ansn = 0, ansu = 0;
vector<int> ans;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
long long fac[maxn];
string st;

void clearu(){
    if(flagu){
        flagu = 0;
        ans.push_back(ansu);
        ansu = 0;
    }
}

void clearn(){
    if(flagn){
        flagn = 0;
        ans.push_back(ansn);
        ansn = 0;
    }
}

long long mypow(long long a, long long b){
    long long ans = 1;
    for(; b; b >>= 1){
        if(b & 1){
            (ans *= a) %= mod;
        }
        (a *= a) %= mod;
    }
    return ans;
}

long long inv(long long x){
    return mypow(x, mod-2);
}

long long C(long long n, long long m){
    return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;
}



int main()
{
    fac[0] = 1;
    for(int i = 1; i <= 1e5; i++){
        fac[i] = (fac[i-1]*i) % mod;
    }
    cin>>st;
    for(int i = 0; i < st.length(); i++){
        if(st[i] == 'm' || st[i] == 'w'){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i = 0; i < st.length(); i++){
        if(st[i] == 'n'){
            clearu();
            if(flagn){
                ansn++;
            } else {
                flagn = 1;
                ansn++;
            }
            continue;
        } else if(st[i] == 'u'){
            clearn();
            if(flagu){
                ansu++;
            } else {
                flagu = 1;
                ansu++;
            }
            continue;
        } else {
            clearn();
            clearu();
        }
    }

    clearn();
    clearu();
    long long ans_v = 1;
    for(auto x : ans){
        long long temp_ans = 1;
        for(int i = 1;  x-2*i >= 0; i++){
            (temp_ans += C(x - i, x-2*i)) %= mod;
        }
        (ans_v *= temp_ans) %= mod;
    }
    cout<<ans_v<<endl;
    return 0;
}
