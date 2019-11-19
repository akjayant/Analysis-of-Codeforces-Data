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
        
        float a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        
        int x, y;
        x = ceil(a / c);
        y = ceil(b / d);
        
        if (x + y <= k) 
            cout<<x<<" "<<y;
        else    
            cout<<"-1";
            
        cout<<endl;    
    }
	
	return 0;
}
