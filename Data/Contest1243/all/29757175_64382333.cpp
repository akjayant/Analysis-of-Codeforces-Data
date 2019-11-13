#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>
#include <iterator>
#include <deque>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull min(ull x, ull y){ if (x<y) return x; return y;}
ull max(ull x, ull y){ if (x<y) return y; return x;}
ll min(ll x, ll y){ if (x<y) return x; return y;}
ll max(ll x, ll y){ if (x<y) return y; return x;}
double min(double x, double y){ if (x<y) return x; return y;}
double max(double x, double y){ if (x<y) return y; return x;}
ull gcd(ull x, ull y){
    if (!x) return y;
    if (!y) return x;
    if (x>y) swap(x,y);
    return gcd(x, y%x);
}
ull inv(ull a, ull c){ // a,c are coprime and a<c
    if (a==1){
        return 1;
    }
    return ((c-(c/a))*inv(c%a,c))%c;
}


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin>>k;
    while (k--){
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        map<pair<char, char>, int> mp;
        for (int i = 0; i < n; i++){
            if (s[i]!=t[i]){
                mp[make_pair(s[i],t[i])]++;
            }
        }
        int f = 0, cnt = 0;
        for (map<pair<char, char>, int>::iterator it = mp.begin(); it != mp.end(); it++){
            f += (it->second)&1;
            cnt += (it->second)>>1;
        }
        if ((f) || (cnt>1)){
            cout<<"No";
        }
        else{
            cout<<"Yes";
        }
        cout<<"\n";
    }

    
}



