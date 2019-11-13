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
        
        for(int i = 0; i < n; i++){
            
            if(a[0][i] == a[1][i]) continue;
            bool yra = false;
            //cout << i << " pora nesutampa " << endl;
            for(int j = i; j < n; j++){
                swap(a[0][i], a[1][j]);
               // cout << "pirma: " << a[0] << " ir " << a[1]<< endl;
                if(a[0] == a[1]) {
                    cout << "Yes\n";
                    yra = true;
                    break;
                }else{
                    swap(a[0][i], a[1][j]);
                    swap(a[1][i], a[0][j]);
                //    cout << "veliau: " << a[0] << " ir " << a[1] << endl;
                    if(a[0] == a[1]) {
                        cout << "Yes\n";
                        yra = true;
                        break;
                    }
                    swap(a[1][i], a[0][j]);
                }

            }
            if(yra) break;
            else {
                cout << "No\n";
                break;
            }
            
        }
        
        
    }
    
    return 0;
}// cba
/// cab
