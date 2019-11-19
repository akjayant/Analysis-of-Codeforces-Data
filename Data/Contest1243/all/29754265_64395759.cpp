#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

long long gcde(long long a, long long b)
{
    if(a == 0) return b;
    return gcde(b%a, a);
}

int main()
{
    long long n;
    cin >> n;

    if(n == 1)
    {
        cout << "1";
        return 0;
    }

    

    vector<long long> vec;

   
    for (long long i = 1; i*i <= n; ++i)
    {
        if(!(n % i))
        {
            if(i != 1) vec.push_back(i);
            if(n/i != 1 ) vec.push_back(n / i);

        }
    }

    long long g = 0;

    for (long long i = 0; i < vec.size(); ++i)
    {
        g = gcde(g, vec[i]);
    }

    cout << g ;

    
    

    return 0;
}