#include<iostream>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

template<typename T, long long modulus=1000000007>
class ModInt {
    private:
        T value_;
    public:
        ModInt() {}
        ModInt(const T& _value) {
            value_ = _value % modulus;
        }
        ModInt(const ModInt& x) {
            value_ = x.value_;
        }
        T getValue() const {
            return value_;
        }
        ModInt& operator=(const ModInt& x) {
            value_ = x.value_;
            return *this;
        }
        ModInt& operator+=(const ModInt& x)  {
            value_ += x.value_;
            if (value_ >= modulus) value_ -= modulus;
            return *this;
        }
        ModInt& operator-=(const ModInt& x) {
            if (value_ < x.value_) value_ += modulus;
            value_ -= x.value_;
            return *this;
        }
        ModInt& operator*=(const ModInt& x) {
            value_ = (value_ * x.value_) % modulus;
            return *this;
        }
        ModInt& operator/=(const ModInt& x) {
            T now_value = x.value_;
            long long cnt = modulus - 2;
            while (cnt > 0) {
                if (cnt & 1) {
                    value_ = (value_ * now_value) % modulus;
                }
                now_value = (now_value * now_value) % modulus;
                cnt /= 2;
            }
            return *this;
        }
        const ModInt operator+(const ModInt& x) const {
            return ModInt(*this) += x;
        }
        const ModInt operator-(const ModInt& x) const {
            return ModInt(*this) -= x;
        }
        const ModInt operator*(const ModInt& x) const {
            return ModInt(*this) *= x;
        }
        const ModInt operator/(const ModInt& x) const {
            return ModInt(*this) /= x;
        }
        ModInt operator++(int) {
            ModInt tmp(*this);
            value_ = (value_ + 1 == modulus ? 0 : value_ + 1);
            return tmp;
        }
        ModInt operator--(int) {
            ModInt tmp(*this);
            value_ = (value_ - 1 < 0 ? modulus - 1 : value_ - 1);
            return tmp;
        }
        friend std::istream& operator>>(std::istream& stream, ModInt& x) {
            stream >> x.value_;
            x.value_ %= modulus;
            return stream;
        }
        friend std::ostream& operator<<(std::ostream& stream, const ModInt& x) {
            stream << x.value_;
            return stream;
        }
};

using ll = long long;
using mint = ModInt<ll>;

mint dp[101010][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = (int)S.size();
    rep(i, 0, N) {
        if (S[i] == 'w' || S[i] == 'm') {
            cout << 0 << endl;
            return 0;
        }
    }
    dp[0][0] = 1;
    rep(i, 1, N + 1) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        if (S[i - 1] == 'n') {
            if (i - 2 >= 0 && S[i - 2] == 'n') {
                dp[i][1] = dp[i - 1][0];
            }
        }
        else if (S[i - 1] == 'u') {
            if (i - 2 >= 0 && S[i - 2] == 'u') {
                dp[i][1] = dp[i - 1][0];
            }
        }
    }
    cout << dp[N][0] + dp[N][1] << endl;
    return 0;
}