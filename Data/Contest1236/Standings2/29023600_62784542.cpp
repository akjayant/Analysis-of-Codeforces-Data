/*
edit : Le Duy Dat
team : THree Wolves
Task:
Link:
*/
#include <bits/stdc++.h>
#define f0(i,a,b) for(int i= a; i<= b; ++i)
#define f1(i,a,b) for(int i= a; i>= b; --i)
#define DEBUG(x) cerr << #x << " = " << x << endl
#define X first
#define Y second
using namespace std;
const long long base=1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const long long MAX_N = 3e5;
/*

 End of Template

*/

/* Action  */
//ll dd[MAX_N];
struct td {
    ll X,Y,Z,T;
    ll QQ;
};
bool cmp(td a, td b) {
    if(a.X != b.X) return a.X < b.X;
    else if(a.Y != b.Y) return a.Y < b.Y;
    else return a.Z < b.Z;
}
ll dd[MAX_N];
void Solves(){
    ll t;
    cin >> t;
    while(t --) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll k = c/2;
        ll ans = min(b, c/2)*3;
        b -= min(b, c/2);
        ans += min(a, b/2)*3;
        cout << ans << "\n";
    }
}

//
int main(){
   // freopen("input.txt", "r", stdin);
	Solves();
}
