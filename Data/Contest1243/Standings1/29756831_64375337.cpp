#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int ans = 0;
        for(int j = 1; j <= n; j++){
        for(int i = 0; i < n; i++){
            if(j <= a[i]){
                if(j <= (n - i)){
                    ans = j;
                }
            }
        }
        }
        cout << ans << endl;
    }
    return 0;
}
