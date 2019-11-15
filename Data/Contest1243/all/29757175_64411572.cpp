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
        int impos = 0;
        vector<pair<int, int> > moves;
        for (int i = 0; i < n; i++){
            if (s[i]!=t[i]){
                int f = 0;
                for (int j = i + 1; j < n; j++){
                    if (s[j]==s[i]){
                        f++;
                        char temp = t[i];
                        t[i] = s[j];
                        s[j] = temp;
                        moves.push_back(make_pair(j+1,i+1));
                        break;
                    }
                }
                if (!f){
                    for (int j = i + 1; j < n; j++){
                        if (t[j]==s[i]){
                            f++;
                            char temp = s[j];
                            s[j] = t[j];
                            t[j] = temp;
                            moves.push_back(make_pair(j+1,j+1));
                            temp = t[i];
                            t[i] = s[j];
                            s[j] = temp;
                            moves.push_back(make_pair(j+1,i+1));
                            break;
                        }
                    }
                }
                if (!f){
                    impos = 1;
                    break;
                }
            }
        }

        if (impos || (moves.size()>2*n)){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
            cout<<moves.size()<<"\n";
            for (int i = 0; i < moves.size(); i++){
                cout<<moves[i].first<<" "<<moves[i].second<<"\n";
            }
        }

    }

    
}



