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
ll mu(ll a, ll n) {
    if(n == 0) return 1;
    if(n == 1) return a % base;
    ll p = mu(a, n/2) % base;
    if(n % 2 == 0) return p*p % base;
    else return p *p % base * a % base;
}
void Solves(){
    ll n;
    cin >> n;
    ll a[n + 1][n + 1];
    int cc = 1;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            for(int j = 1; j <= n; j++) a[j][i] = cc ++;
        }
        else {
            for(int j = n; j >= 1; j--) a[j][i] = cc ++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
}

//
int main(){
  //  freopen("input.txt", "r", stdin);
	Solves();
}
