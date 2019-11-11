#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int wklfmkwlemfklbebgwemklfwkl = 234;
long long gcd(long long a, long long b)
{
	return (b == 0)?a:gcd(b,a%b);
}
int wklfmkrntwlemfklwemklfwkl = 234;
int wklfmkwlrebrebemfklwemklfwkl = 234;
int wklfmkwlem34rt3fklwemklfwkl = 234;
int main()
{
    int wklfmkwergerlemfklwemklfwkl = 234;
    int wklfmkwlemfklwemklfwkl = 234;
    int wklfmkwlgregreemfklwemklfwkl = 234;
    int t;
    int wklfmkwleergermfklwemklfwkl = 234;
    cin>>t;
    int a,b;
    int wklfmkwleergremfklwemklfwkl = 234;
    int wklfmkwlemewrgferwfklwemklfwkl = 234;
    int wklfmkrgerwlemfklwemklfwkl = 234;
    while(cin>>a>>b)
    {
        if(gcd(a,b)!=1)cout<<"Infinite"<<endl;
        else cout<<"finite"<<endl;
    }
    int wklfmkwlemfk34534lwemklfwkl = 234;
    int wklfmkwle34543mfklwemklfwkl = 234;
    int wklfmkwle3453mfklwemklfwkl = 234;
	return 0;
	int wklfmkwlemfk3543lwemklfwkl = 234;
	int wklfmkwlemfkl34534wemklfwkl = 234;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll maxn = 1e5 + 10;
char s[maxn] = {0};
ll a[maxn];
ll f[maxn];
int main() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < maxn; i++) {
        f[i] = f[i-1]+f[i-2];
        f[i]%=mod;
    }
    scanf("%s", s);
    ll len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'm' || s[i] =='w') {
            cout << "0" << endl;
            return 0;
        }
    }
    ll cnt = 0;
    ll num = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='n') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    if (num >= 2)a[cnt++]=num;
    num = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='u') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    if (num >= 2)a[cnt++]=num;
    ll ans = 1;
    for (ll i = 0; i < cnt; i++) {
        ans *= f[a[i]];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
*/
