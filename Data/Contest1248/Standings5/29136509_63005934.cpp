//Ima fall asleep
#include <iostream>
#define ll long long
using namespace std;
long long fibonacci(long long n, long long m) {
    long long result;
    long long index;
    long long period = n+1;
    long long sz = min (n+1,m*m+1);
    long long *F = new long long[sz];
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;

    for (long long i = 3; i < sz; i++)
    {
      F[i] = (F[i-2] + F[i-1]) % m;
      if (F[i] == 1 && F[i-1] == 0) 
      {
        period = i-1;
        break;
      }
    }

    index = n % period;
    result = F[index];
    delete[]F;
    return result;

}

int main()
{
    int n,m; cin >> n >> m;
    ll mod = 1000000007;
    ll rtn1 = 0, rtn2 = 0;
    rtn1 = (fibonacci(n+1, mod)*2)%mod;
    rtn2 = (fibonacci(m+1, mod)*2)%mod - 2;
    cout << (rtn1 + rtn2)%mod << "\n";
    return 0;
}
