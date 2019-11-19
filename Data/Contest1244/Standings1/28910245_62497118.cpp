#include <bits/stdc++.h>
using namespace std;
#define re return
#define ll long long
#define du double
#define co continue
#define gcd __gcd
#define br break
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fast();
    ll n,k;
    cin >> n >> k;
    ll a[n+10];
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1);
    ll mn=a[1],mx=a[n];
    multiset <ll> m;
    for (int i=1;i<=n;++i){
        m.insert(a[i]);
    }
    ll k1=0,k2=0;
    ll mni=1,mxi=n;
    while (k>0 && mn!=mx){
        //cout << k << " " << mni << " " << mxi << endl;
        if (k1+m.count(a[mni])<=k || k2+m.count(a[mxi])<=k){
            if (k1+m.count(a[mni])<=k2+m.count(a[mxi])){
                k1+=m.count(a[mni]);
                while (a[mni]==a[mni+1] && mni<mxi) mni++;
                mni++;
                k-=k1*(a[mni]-mn);
                mn=a[mni];
                //cout << "lol" << " " << k << endl;
                if (k<0){
                    k=-k;
                    //cout << mx << " " << mn << " " << k-1 << " " << k1 << endl;
                    cout << mx-mn+(k-1)/k1+1;
                    re 0;
                }
            }
            else{
                k2+=m.count(a[mxi]);
                while (a[mxi]==a[mxi-1] && mni<mxi) mxi--;
                mxi--;
                k-=k2*(mx-a[mxi]);
                mx=a[mxi];
                if (k<0){
                    k=-k;
                    //cout << mx << " " << mn << k-1 << k1 << endl;
                    cout << mx-mn+(k-1)/k2+1;
                    re 0;
                }
            }
        }
        else br;
    }
    cout << mx-mn;
    re 0;
}
/*
4 14
1 1 9 9
*/
