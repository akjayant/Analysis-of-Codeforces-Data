#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define vpl vector<pl>
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005
using namespace std;
int t , n;
char a;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int mx1 = INF;
        for(int i = 1; i <= n; i++){

            cin >> a;
            if(a=='1'){
                mx1 = min(mx1,i);
                mx1 = min(mx1,n-i+1);
            }

        }
        cout << max(2*n - 2*mx1 + 2,n) <<  '\n';

    }
    return 0;
}
