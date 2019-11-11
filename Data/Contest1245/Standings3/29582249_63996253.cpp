//
//  main.cpp
//  Codeforces Round #597 (Div. 2)
//
//  Created by Augustinas Jucas on 01/11/2019.
//  Copyright © 2019 Augustinas Jucas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    
    if (a == b)
        return a;
    
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while(t--){
        
        int a, b;
        cin >> a >> b;
        if(gcd(a, b) != 1){
            cout << "Infinite";
        }else cout << "Finite";
        cout << "\n";
        
    }
    
    return 0;
}
