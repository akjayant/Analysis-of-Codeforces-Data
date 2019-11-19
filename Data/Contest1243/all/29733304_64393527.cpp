#include<bits/stdc++.h>
using namespace std;
bool is_prime(long long n){
    long long sqr = sqrt(n);
    if(n == 2 || n == 3){
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for(long long i = 5; i <= sqr; i += 6){
        if(n % i == 0 || (n % (i + 2) == 0)){
            return false;
        }
    }
    return true;
}
vector<long long> find_divisors(long long n){

    long long sqr = sqrt(n);
    vector<long long>answer;
    if(is_prime(n)){
        answer.push_back(n);
        return answer;
    }
    for(long long i = 2; i <= sqr; ++i){
        if(n % i == 0){
            if(n / i == i){
                answer.push_back(i);
            }
            else{
                answer.push_back(i);
                answer.push_back(n/i);
            }
        }
    }
    return answer;
}
long long find_gcd(long long a , long long b){
    if(b == 0){
        return a;
    }
    return find_gcd(b , a % b);
}
int main(){
    long long n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    vector<long long>divisors = find_divisors(n);
    long long p = divisors.size();
    long long gcd = 0;
    for(long long i = 0; i < p; ++i){
        gcd = find_gcd(divisors[i] , gcd);
    }
    cout << gcd << "\n";


return 0;}
