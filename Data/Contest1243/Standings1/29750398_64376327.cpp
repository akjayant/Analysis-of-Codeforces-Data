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

const int maxn = 2000 + 5;
int a[maxn];

int32_t main(){
    int Q;
    cin >>Q;
    while(Q --){
        int n;
        cin >>n;
        for(int i = 0; i < n; i ++){
            cin >>a[i];
        }
        sort(a, a + n);
        int ans = 0;
        for(int i = n - 1; i >= 0; i --){
            xmax(ans, min(n - i, a[i]));
        }
        cout <<ans <<'\n';
    }
    return false;
}
