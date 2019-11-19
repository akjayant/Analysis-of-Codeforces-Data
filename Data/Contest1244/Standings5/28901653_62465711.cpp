// I can't live in a fairytale of lies

#include<bits/stdc++.h>

#define s second
#define f first
#define pb push_back
#define int ll
#define D(x) cerr<<#x<<": "<<x<<endl
#define D2(x) cerr<<#x<<": "<<x<<' '

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MAX=2e6,mod=1e9+7,INF=1e15,sq=320;

int n,k,q,m,ans,a,b,c,d;
vi v;

/*void compress(){
    for(int i=0;i<n;i++) v.pb(a[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<n;i++){
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin()+1;
    }
}*/

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d >> k;
        int x = (a+c-1)/c;
        int y = (b+d-1)/d;
        if(y+x > k) cout << -1 << '\n';
        else cout << x << ' ' << y << '\n';
    }
    return -0;
}



