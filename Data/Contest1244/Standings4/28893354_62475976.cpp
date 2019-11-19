#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
const long long MOD = 1e9 + 7;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    
    while (t--) {
        
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        int ans = n;
        for (int i=0;i<n;i++) 
            if (s[i] == '1') {
                ans = max(ans, 2 * (i + 1));
                ans = max(ans, 2 * (n - i));   
            }    
        
        cout<<ans<<endl;    
    }
	
	return 0;
}
