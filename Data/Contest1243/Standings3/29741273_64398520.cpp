#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(long long n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    

    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    for (long long i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    
    return true;
}
int main(int argc, const char * argv[]) {
    long long n;
    cin >> n;
    if(isPrime(n)){
        cout << n ;
    }else{
        if(n == 1) cout << "1";
        else if(n == 4) cout << "2";
        else {
            long long sk = sqrt(n);
            long long kt = n;
            for(long long i = 2; i <= sk; i++){
                if(kt % i == 0){
                    while(kt % i == 0){
                        
                        kt /= i;
                    }
                    if(kt == 1){
                        cout << i;
                        return 0;
                        
                    }
                    cout << "1" ;
                    return 0;
                }
            }
            cout << "1";
            
        }
    }
    
}
