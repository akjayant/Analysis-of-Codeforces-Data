#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

struct PrimeFactory {
    std::random_device rd;
    vector<int> prime;

    PrimeFactory(int n) {
        vector<int> A(n, 1);
        A[0] = A[1] = 0;
        for (int i = 0; i < n; i++)
            if (A[i])
                for (int j = i + i; j < n; j += i)
                    A[j] = 0;
        for (int i = 0; i < n; i++)
            if (A[i])
                prime.push_back(i);
        // cout << "prime: " << prime << endl;
    }

    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long mul_mod(long long a, long long b, long long m) {
        long long ans = 0;
        a %= m;
        b %= m;

        while (b) {
            if (b & 1ll) {
                ans = ans + a;
                if (ans >= m)
                    ans -= m;
            }
            a <<= 1;
            if (a >= m)
                a -= m;
            b >>= 1;
        }

        return ans;
    }

    long long pow_mod(long long a, long long n, long long m) {
        long long ans = 1;

        while (n) {
            if (n & 1) {
                ans = mul_mod(ans, a, m);
            }
            n >>= 1;
            a = mul_mod(a, a, m);
        }

        return ans;
    }

    int fermat_prime_test(long long n) {
        std::uniform_int_distribution<long long> dist(0, numeric_limits<long long>::max());

        if (n == 2 || n == 3)
            return 1;

        if (n % 2  == 0)
            return 0;

        if (n % 3 == 0)
            return 0;

        for (int i = 0; i < 10; i++) {
            long long a = dist(rd) % (n - 4) + 2;
            long long val = pow_mod(a, n -1 , n);
            if (val != 1)
                return 0;
        }

        return 1;
    }

    long long pollard_rho(long long n, long long c) {
        long long x = 2, y = 2;
        long long d = 1;

        while (d == 1) {
            x = (mul_mod(x, x, n) + c) % n;
            y = (mul_mod(y, y, n) + c) % n;
            y = (mul_mod(y, y, n) + c) % n;
            d = gcd(abs(x - y), n);
        }

        return d;
    }

    long long pollard_one_factor(long long n) {
        long long d = n;
        long long c = 2;
        while (d == n)
            d = pollard_rho(n, c++);
        return d;
    }

    void factor(long long n, map<long long, int>& M) {
        M.clear();
        for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++) {
            while (n % prime[i] == 0) {
                M[prime[i]]++;
                n /= prime[i];
            }
        }
        if (n > 1)
            M[n]++;
    }

    void factor(long long n, vector<long long>& F) {
        F.clear();
        for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++) {
            while (n % prime[i] == 0) {
                F.push_back(prime[i]);
                n /= prime[i];
            }
        }
        if (n > 1)
            F.push_back(n);
    }

    map<long long, int> _M;
    long long euler_totient(long long n) {
        map<long long, int>& M = _M; // memoery reuse
        factor(n, M);
        for (auto p: M)
            n = n / p.first * (p.first - 1);
        return n;
    }

    void pollard_factor(long long n, map<long long, int>& M) {
        vector<long long> F;
        factor(n, F);

        if (!fermat_prime_test(F.back())) {
            long long a = F.back();
            F.pop_back();
            long long b = pollard_one_factor(a);
            F.push_back(b);
            F.push_back(a / b);
        }

        M.clear();
        for (auto a: F)
            M[a]++;
    }
};

PrimeFactory factory(1e6 + 100);

vector<long long> F;
long long solve(long long n) {
    if (n == 1)
        return 1;
    factory.factor(n, F);
    sort(F.begin(), F.end());
    F.erase(unique(F.begin(), F.end()), F.end());
    /*
    cout << "n: " << n << endl;
    cout << "F: " << F << endl;
    */
    if (F.size() == 1)
        return F[0];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    long long ans = solve(n);
    cout << ans << endl;
    return 0;
}
