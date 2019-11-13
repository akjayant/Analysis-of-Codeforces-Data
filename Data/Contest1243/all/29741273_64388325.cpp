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
        string a[2];
        cin >> a[0] >> a[1];
        
        vector<pair<int, int>> ats;
        
        for(int i = 0; i < n; i++){
            
            if(a[0][i] == a[1][i]) continue;
            
            for(int j = i+1; j < n; j++){
                if(a[0][j] == a[0][i]){
                    swap(a[0][j], a[1][i]);
                    ats.push_back({j, i});
                    break;
                }
                if(a[0][i] == a[1][j]){
                    
                    swap(a[0][j], a[1][j]);
                    swap(a[0][j], a[1][i]);
                    
                    ats.push_back({j, j});
                    ats.push_back({j, i});
                    break;
                }
            }
            
        }
        if(a[0] == a[1]) {
            cout << "Yes\n" << ats.size() << "\n";
            for(int i = 0; i < ats.size(); i++){
                cout << ats[i].first+1 << " " << ats[i].second+1 << "\n";
                
            }
        }else cout << "No\n";
    }

    
    return 0;
}// cba
/// cab

/*
 acb
 acb
 
 
 
 */
