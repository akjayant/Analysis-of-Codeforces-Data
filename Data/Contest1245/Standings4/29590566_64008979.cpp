#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

#define ll long long
#define vll vector<long long>

#define fori(a, b) for(ll i = a;i <= b;i++)
#define forj(a, b) for(ll j = a;j <= b;j++)
#define fork(a, b) for(ll k = a;k <= b;k++)

#define input2(a, b) cin >> a >> b;
#define input(a) cin >> a;

#define max(a,b) (a<b?b:a)
#define min(a,b) (a>b?b:a)

using namespace std;

ll MOD = 1;

ll power(ll x, ll n, ll mod){
    if(n == 0){
        return 1;
    }
    ll temp = power(x, n/2, mod);
    if(n % 2 == 1){
        return (x*temp*temp)%mod;
    } else {
        return (temp*temp)%mod;
    }
}
ll abs(ll a, ll b){
    if(a > b){
        return a - b;
    }
    return b - a;
}
ll XOR(ll a, ll b){
    ll result = 0;
    ll add = 1;
    while(a != 0 || b != 0){
        //cout << a << " " << b << endl;
        if(a % 2 != b % 2){
            result += add;
        }
        a /= 2;
        b /= 2;
        add *= 2;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    ll t;
    cin >> t;
    ll n,a,b,c;
    string str;
    ll win;
    ll rps[3];
    ll spare[3];
    string spareC[3] = {"P","S","R"};
    fori(0, t-1){
        cin >> n >> a >> b >> c;
        cin >> str;
        win = 0;
        rps[0] = 0;
        rps[1] = 0;
        rps[2] = 0;
        forj(0, str.length()-1){
            if(str[j] == 'R'){
                rps[0]++;
            } else if(str[j] == 'P'){
                rps[1]++;
            } else {
                rps[2]++;
            }
        }
        win += min(rps[0],b);
        win += min(rps[1],c);
        win += min(rps[2],a);
        spare[0] = b - rps[0];
        spare[1] = c - rps[1];
        spare[2] = a - rps[2];
        forj(0, 2){
            if(spare[j] < 0){
                spare[j] = 0;
            }
        }
        rps[0] = b - spare[0];
        rps[1] = c - spare[1];
        rps[2] = a - spare[2];
        //cout << spare[0] << spare[1] << spare[2] << endl;
        if(win * 2 < n){
            cout << "NO" << endl;
            continue;
        } else {
            cout << "YES" << endl;
        }
        forj(0, str.length()-1){
            //cout << j << endl;
            if(str[j] == 'R'){
                if(rps[0] > 0){
                    cout << "P";
                    rps[0]--;
                    continue;
                }
                fork(0,2){
                    if(spare[k] > 0){
                        cout << spareC[k];
                        spare[k]--;
                        break;
                    }
                }
            } else if(str[j] == 'P'){
                if(rps[1] > 0){
                    cout << "S";
                    rps[1]--;
                    continue;
                }
                fork(0,2){
                    if(spare[k] > 0){
                        cout << spareC[k];
                        spare[k]--;
                        break;
                    }
                }
            } else {
                if(rps[2] > 0){
                    cout << "R";
                    rps[2]--;
                    continue;
                }
                fork(0,2){
                    if(spare[k] > 0){
                        cout << spareC[k];
                        spare[k]--;
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
