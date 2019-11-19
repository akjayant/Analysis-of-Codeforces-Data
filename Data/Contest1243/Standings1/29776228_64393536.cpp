#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

long long n;
int main(){
    cin >> n;
    long long ans = n;
    for(int i=2;i*1LL*i<=n;i++){
        if(n%i == 0){
            // find p
            ans = i;
            while(n%i == 0) n/=i;
            if(n!=1){
                ans = 1;
                break;
            }
        }
    }
    cout << ans;
    
    return 0;
}


