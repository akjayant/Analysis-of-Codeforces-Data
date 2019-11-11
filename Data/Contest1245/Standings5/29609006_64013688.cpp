/*cout<<"─────────▄──────────────▄"<<endl;
    cout<<"────────▌▒█───────────▄▀▒▌"<<endl;
    cout<<"────────▌▒▒▀▄───────▄▀▒▒▒▐"<<endl;
    cout<<"───────▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐"<<endl;
    cout<<"─────▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐"<<endl;
    cout<<"───▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀██▀▒▌"<<endl;
    cout<<"──▐▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▒▌much speed"<<endl;
    cout<<"──▌▒▒▐▄█▀▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐"<<endl;
    cout<<"─▐▒▒▒▒▒▒▒▒▒▒▒▌██▀▒▒▒▒▒▒▒▒▀▄▌"<<endl;
    cout<<"─▌▒▀▄██▄▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌"<<endl;
    cout<<"─▌▀▐▄█▄█▌▄▒▀▒▒▒▒▒▒░░░░░░▒▒▒▐ Wow"<<endl;
    cout<<"▐▒▀▐▀▐▀▒▒▄▄▒▄▒▒▒▒▒░░░░░░▒▒▒▒▌"<<endl;
    cout<<"▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐"<<endl;
    cout<<"─▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌good macro"<<endl;
    cout<<"─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐"<<endl;
    cout<<"──▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▌"<<endl;
    cout<<"────▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀"<<endl;
    cout<<"───▐▀▒▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀"<<endl;
    cout<<"──▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀"<<endl;*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll maxn = 1e5 + 10;
char s[maxn] = {0};
ll a[maxn], f[maxn];

int solve(){
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < maxn; i++) {f[i] = f[i-1]+f[i-2];f[i]%=mod;}
    scanf("%s", s);
    ll len = strlen(s);
    for (int i = 0; i < len; i++) {if (s[i] == 'm' || s[i] =='w') {cout << "0" << endl;return 0;}}
    ll adshfj = 0;
    ll po = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='n') po++;
        else {
            if (po >= 2)a[adshfj++]=po;
            po=0;
        }
    }
    if (po >= 2)a[adshfj++]=po;
    po = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='u')  po++;
        else {
            if (po >= 2)a[adshfj++]=po;
            po=0;
        }
    }
    if (po >= 2)a[adshfj++]=po;
    ll res = 1;
    for (ll i = 0; i < adshfj; i++) {res *= f[a[i]];res %= mod;}
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
