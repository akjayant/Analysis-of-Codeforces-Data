//404 Not Found {=}7 (o)7 (x)7
#include<bits/stdc++.h>
using namespace std;
#define apppend push_back
#define endl "\n"
#define dbug(x) cout<<#x<<"="<<x<<endl

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5, inf = 1e9, mod= 1e9+7;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setprecision(30);
    int q;
    cin >> q;
    while(q--)
    {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        a = ceil((double)a/(double)c);
        b = ceil((double)b/(double)d);
        if(a+b>k)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << a << " " << b <<  endl;
        }
        
    }
    return 0;
}