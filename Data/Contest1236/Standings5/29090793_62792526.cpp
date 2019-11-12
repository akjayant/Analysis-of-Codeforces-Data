#include <iostream>
using namespace std;
const long long mod=1000000000+7;
long long stepen(long long st, long long num) {
    if (st==0) return 1;
    if (st%2==0) {
        long long s=stepen(st/2,num);
        return (s*s)%mod;
    }
    return (stepen(st-1,num)*num)%mod;
}
int main () {
    long long n, m;
    cin >> n >> m;
    cout << stepen(n,stepen(m,2)-1) << endl;
    return 0;
}
