#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define num     long long

num totient(num n) {
    num result = n;
    for (num i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

num minimumPrime(num X) {
    for (num d=2; d*d<=X; ++d)
        if (X%d == 0) return d;
    return X;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    num N;  input >> N;
    num X = N;

    if (N == 1) {
        output << 1 << '\n';
    }
    else {
        num pf = minimumPrime(X);
        while (X%pf == 0) X/=pf;

        if (X != 1) output << 1 << '\n';
        else        output << pf << '\n';
    }

    return 0;
}
