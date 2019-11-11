#include <bits/stdc++.h>
#define loop(i, a, b) for(long long  i=a;i<b;i++)
#define mn 500100
#define mod 1000000007
 
using namespace std;
 
typedef long long ll;

ll euc(ll a, ll b){
    if(a%b==0) return b;
    return euc(b, a%b);
}

int main() {
    ll t; cin >> t;
    loop(afskifn, 0, t){
        ll a, b, c, n; cin >> n >> a >> b >> c;
        ll r=0, p=0, s=0;
        char arr[n];
        loop(i, 0, n){
            char t;
            scanf(" %c ", &t);
            arr[i]=t;
            if(t=='R') r++;
            if(t=='P') p++;
            if(t=='S') s++;
            
        }
        ll ans=min(b, r)+min(c, p)+min(a, s);
        ll tb=min(b, r), tc=min(c, p), ta=min(a, s);
        ll ob=b-tb, oc=c-tc, oa=a-ta; 
        if(ans>=(n+1)/2){ 
            cout << "YES"<<endl;
            loop(i, 0, n){
                if(arr[i]=='R' and tb){
                    cout << "P";
                    tb--;
                }
                else if(arr[i]=='P' and tc){
                    cout << "S";
                    tc--;
                }
                else if(arr[i]=='S' and ta){
                    cout << "R";
                    ta--;
                }
                else{
                        if(ob){
                            cout << "P";
                            ob--;
                        }
                        else if(oc){
                            cout << "S";
                            oc--;
                        }
                        else if(oa){
                            cout << "R";
                            oa--;
                        }
                }
                
            }
            cout << endl;
        }
        else cout << "NO"<<endl;
    }
}