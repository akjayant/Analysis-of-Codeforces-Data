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
long long fib[100001];
const int mod = 1000000007;
void fibo(int kek){
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < kek; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fibo(100001);
    string a;
    int ats = 1;
    cin >> a;
    char kas = '-';
    int kek = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'm' || a[i] == 'w') {
            cout << "0";
            return 0;
        }
        
        if(a[i] == kas){
            kek++;
        }else{
            if(kas != '-'){
                ats = (ats * (fib[kek])%mod);
                //cout << "Baigesi " << kas << "intervalas, ilgis = " << kek;
                //cout << endl;
                kas = '-';
                kek = 0;
            }
            if(a[i] == 'n') {kas = 'n'; kek = 1;}
            else if(a[i] == 'u'){kas = 'u'; kek = 1;}
            else continue;
        }
    }
    if(kas != '-'){
        ats = (ats * (fib[kek])%mod);
//        cout << "Baigesi " << kas << "intervalas, ilgis = " << kek;
  //      cout << endl;
        kas = '-';
        kek = 0;
    }
    cout << ats ;
    return 0;
}
