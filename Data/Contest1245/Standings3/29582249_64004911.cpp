//
//  main.cpp
//  Codeforces Round #597 (Div. 2)
//
//  Created by Augustinas Jucas on 01/11/2019.
//  Copyright © 2019 Augustinas Jucas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while(t--){
        
        int n, r, p, s;
        cin >> n >> r >> p >> s;
        int kek = 0;
        string ats = "";
        for(int i = 0; i < n; i++){
            char a;
            cin >> a;
            
            if(a == 'R'){
                if(p > 0){
                    p--;
                    kek++;
                    ats.push_back('P');
                }else  ats.push_back('?');
            }
            if(a == 'P'){
                if(s > 0){
                    s--;kek++;
                    ats.push_back('S');
                }else  ats.push_back('?');
            }
            if(a == 'S'){
                if(r > 0){
                    r--;kek++;
                    ats.push_back('R');
                }else  ats.push_back('?');
            }
        }
        for(int i = 0; i < n; i++){
            if(ats[i] == '?'){
                if(p > 0) {ats[i] = 'P'; p--;}
                else if(s > 0) {ats[i] = 'S'; s--;}
                else if(r > 0) {ats[i] = 'R'; r--;}
            }
        }
        //cout << kek << " ir " << ceil(n/2) << endl;
        if(kek >= ceil((double)n/2)){
            cout << "YES\n" << ats << "\n";
        }else cout << "NO\n";
        
        
        
    }
    
    return 0;
}
