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

const int maxn = 0;

int32_t main(){
    int Q;
    cin >>Q;
    while(Q --){
        int a, b;
        cin >>a >>b;
        if(__gcd(a, b) == 1)
            cout <<"Finite" <<' ';
        else
            cout <<"Infinite" <<' ';
    }
    return false;
}
