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
        string s, t;
        cin >> s >> t;
        int cnt = 0;
        int p1 = -1, p2 = -1;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                if(p1 == -1){
                    p1 = i;
                }else{
                    p2 = i;
                }
                cnt++;
            }
        }
        if(cnt > 2){
            cout << "No";
        }else{
            if(s[p1] == s[p2] && t[p2] == t[p1]){
                cout << "Yes";
            }else{
                cout << "No";
            }
        }
        cout << endl;
    }
    return 0;
}
