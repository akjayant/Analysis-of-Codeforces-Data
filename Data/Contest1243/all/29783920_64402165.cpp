#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long sq = (long long)(sqrt(n)) + 2;
    int z = 0;
    for (long long i = 2; i < sq; i++){
        if (n % i == 0){
            while (n % i == 0){
                n /= i;
            }
            if (n == 1){
                cout << i;
                exit(0);
            }
            else {
                cout << 1;
                exit(0);
            }
        }
    }
    cout << n;
}

