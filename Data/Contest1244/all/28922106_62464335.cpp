#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back;
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>

#ifdef LOCAL
#define debug(x) cout<<#x<<" "<<(x)<<endl;
#else
#define debug(x)
#endif

struct fast_io{
    fast_io(){
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cout<<fixed<<setprecision(12);
    }
}____;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        if(ceil((ld)a / c) + ceil((ld)b / d) <= k){
            cout<<(int)ceil((ld)a / c)<<" "<<(int)ceil((ld)b / d)<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
