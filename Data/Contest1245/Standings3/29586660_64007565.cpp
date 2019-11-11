#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5+10;
const int mod = 1e9+7;
string str;
ll fib[N];
int n;
void init(){
    fib[1] = 1;
    fib[2] = 2;
    for(int i=3;i<=n;++i)   fib[i] = (fib[i-1]+fib[i-2])%mod;
}
int main(){
    cin >> str;
    n = str.length();
    int sign = 0;
    init();
    vector<int> ct;
    for(int i=0;i<n;++i){
        if(str[i]=='w' || str[i]=='m')  sign = 1;
        else if(str[i]=='n'){
            int cnt = 1;
            while(i<n && str[++i]=='n')    cnt++;
            i--;
            ct.push_back(cnt);
        }
        else if(str[i]=='u'){
            int cnt = 1;
            while(i<n && str[++i]=='u')     cnt++;
            i--;
            ct.push_back(cnt);
        }
    }
    if(sign) cout << "0\n";
    else{
        ll ans = 1;
        for(auto v:ct){
            ans  = ans * fib[v] %mod;
        }
        cout << ans << '\n';
    }
    return 0;
}