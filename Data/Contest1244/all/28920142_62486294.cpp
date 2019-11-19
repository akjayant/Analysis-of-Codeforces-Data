#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define INF 1000000000000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    string s;
    cin >> t;

    while(t--){
        cin >> n >> s;
        int ans = n, x = -1, y = -1;
        for(int i = 0; i < n; i++){

            if(x == -1 && s[i] == '1'){
                x = i;
            }

            else if(s[i] == '1'){
                y = i;
            }
        }

        if(x != -1 && y != -1){
            ans = max(2*(n-x), 2*(y+1));
        }
        else if(x != -1){
            ans = max(2*(x+1), 2*(n-x));
        }
        cout << ans << endl;
    }
    return 0;
}