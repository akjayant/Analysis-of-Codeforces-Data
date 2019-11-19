#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 0; tt < t; ++tt){
        int n;
        cin >> n;
        int left = n+1;
        int right = -1;
        for(int j = 0; j < n; ++j){
            char c;
            cin >> c;
            if(c == '1'){
                if(j < left) left = j;
                if(j > right) right = j;
            }
        }
        if(left == n+1 && right == -1){
            cout << n << "\n";
        }else{
            cout << max(2*right+2,2*(n-left)) << "\n";
        }
    }
}