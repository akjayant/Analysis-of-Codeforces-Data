///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

vector < ll > v;

int32_t main(){
    int n;
    cin >>n;
    if(n == 1)
        return cout <<1 <<endl, false;
    for(int i = 2; i* i <= n; i ++){
        if(!(n% i))
            v.pb(i);
        while(!(n% i))
            n /= i;
    }
    if(n > 1)
        v.pb(n);
    if(SZ(v) > 1)
        cout <<1 <<endl;
    else
        cout <<v[0] <<endl;
    return false;
}
