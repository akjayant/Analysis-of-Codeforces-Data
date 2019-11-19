#include <bits/stdc++.h>

using namespace std ;

#define N 100005
#define pb push_back
#define ll long long
#define mod 1000000007
#define pll pair<ll, ll>
#define double long double
#define fi first
#define se second
#define INF 10000000000000000
#define Base 1200

int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    string s;
    int n;
    cin >> testcase;
    while(testcase--){
        cin >> n;
        cin >> s;
        int ans = n;
        for(int i = 0 ; i < n ; i ++){
            if(s[i] == '1'){
                ans = max(ans , max(i + 1 , n - i) * 2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}


