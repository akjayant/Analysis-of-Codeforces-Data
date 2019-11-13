#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        vector<int> eil;
        for(int i = 0; i < n; i++){
            int a;
            
            cin >> a;
            eil.push_back(a);
        }
        sort(eil.begin(), eil.end(), greater<int>());
        int ats = 0;
        for(int i = 0; i < n; i++){
            int side = min(eil[i], i+1);
            ats = max(ats, side);
        }
        cout << ats << "\n";
        
    }
    
    return 0;
}
