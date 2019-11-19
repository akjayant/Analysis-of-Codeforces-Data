#include <vector>
#include <cstdio>

#ifdef DBG
    #define D(y) y
#else
    #define D(y)
#endif

using namespace std;

const int NB = 32;

struct bin {
    long long prefix;
    int suffix_len;
};

long long count_possibilities(bin a, bin b) {
    D(printf("count(%lld %d, %lld %d)\n", a.prefix, a.suffix_len, b.prefix, b.suffix_len));
    long long res = 1;
    for (int i = 0; i < NB; ++i) {
        int abit;
        if (a.suffix_len > 0) {
            a.suffix_len--;
            abit = -1;
        } else {
            abit = a.prefix & 1;
            a.prefix >>= 1;
        }

        int bbit;
        if (b.suffix_len > 0) {
            b.suffix_len--;
            bbit = -1;
        } else {
            bbit = b.prefix & 1;
            b.prefix >>= 1;
        }

        if (abit < 0 && bbit < 0) {
            res *= 3;
        } else if (abit < 0) {
            res *= (bbit == 0 ? 2 : 1);
        } else if (bbit < 0) {
            res *= (abit == 0 ? 2 : 1);
        } else if (abit == 1 && bbit == 1) {
            D(printf("    IS 0\n"));
            return 0;
        }
    }
    D(printf("    IS %lld\n", res));

    return res;
}

vector<bin> iterate(long long m) {
    vector<bin> res;
    int suffix_len = 0;
    res.push_back({m, 0});
    while (m > 0) {
        if ((m & 1) == 1) {
            res.push_back({m ^ 1, suffix_len});
        }
        m >>= 1;
        suffix_len++;
    }
    return res;
}

long long solve(long long m1, long long m2) {
    D(printf("\nsolving (%lld, %lld)\n", m1, m2));
    if (m1 < 0 || m2 < 0) return 0;
    if (m1 == 0) return m2 + 1;
    if (m2 == 0) return m1 + 1;

    long long answer = 0;
    vector<bin> iter_m1 = iterate(m1);
    vector<bin> iter_m2 = iterate(m2);
    for (int i = 0; i < iter_m1.size(); ++i) {
        for (int j = 0; j < iter_m2.size(); ++j) {
            answer += count_possibilities(iter_m1[i], iter_m2[j]);
        }
    }

    D(printf("solve(%lld, %lld) = %lld\n", m1, m2, answer));

    return answer;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", solve(r, r) - solve(r, l - 1) - solve(l - 1, r) + solve(l - 1, l - 1));
    }

    return 0;
}
