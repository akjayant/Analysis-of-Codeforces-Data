#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define for0(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define int long long

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

int n, y = 0;

signed main(){
   // ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

 cin >> n;
 int A[n][n];

 for(int i = 0; i < n; i++){
    if(i%2 == 0) for(int j = 0; j < n; j++) {
        y++;
        A[i][j] = y;
    }
    else for(int j = n-1; j >= 0; j--){
        y++;
        A[i][j] = y;
    }
 }

 for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cout << A[j][i]<<' ';
    cout<< endl;
 }

}

