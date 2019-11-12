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
    ll k,n,v,sum,mn,f;
    string s,t;
    ll ans1[120],ans2[120];
    cin >> k;
    char p;
    ll a[1000+10];
    ll mas[30+10];
    while(k--){
        sum=0;
        cin >> n;
        cin >> s;
        cin >> t;
        for (int i=0;i<=30;++i) mas[i]=0;
        for (int i=0;i<n;++i){
            mas[s[i]-'a']++;
            mas[t[i]-'a']++;
        }
        f=0;
        for (int i=0;i<=30;++i){
            //cout << mas[i];
            if (mas[i]%2){
                f=1;
                cout << "NO" << "\n";
                br;
            }
        }
        if (f)co;
        cout << "YES" << "\n";
        for (int i=0;i<n;++i){
            if (s[i]!=t[i]){
                for (int j=i+1;j<n;++j){
                    if (s[j]==s[i]){
                        sum++;
                        ans1[sum]=j+1;
                        ans2[sum]=i+1;
                        swap(s[j],t[i]);
                        br;
                    }
                    if (t[j]==s[i]){
                        sum++;
                        ans1[sum]=j+1;
                        ans2[sum]=j+1;
                        swap(s[j],t[j]);
                        sum++;
                        ans1[sum]=j+1;
                        ans2[sum]=i+1;
                        swap(s[j],t[i]);
                        br;
                    }
                }
            }
        }
        cout << sum << "\n";
        for (int i=1;i<=sum;++i) cout << ans1[i] << " " << ans2[i] << "\n";
    }
    re 0;
}
