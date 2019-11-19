#include<bits/stdc++.h>
using namespace std;
const int MX = 1009;

int T , n;
pair < int , int > arr[MX];
int main() {
    // freopen("exptree.in","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        string str;
        int n;
        cin >> n >> str;
        int mn = n , mx = -1;
        for(int j = 0 ; j < str.size() ; j++)
            if(str[j] == '1') {mn = min(mn , j) , mx = max(mx , j);}
        if (str[0] == '1' || str[n - 1] == '1') cout << n * 2 << endl;
        else if (mx == -1) cout<<n<<endl;
        else {
            int ans = max(n - mn , mx + 1) * 2;
            if(mx != mn){
                ans = max(ans , (mx - mn + 1) * 2 + max(mn + 1 , n - mx - 1));
            }
            ans = max(ans , n);
            cout<<ans<<endl;
        }

    }
}