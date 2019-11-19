#include <bits/stdc++.h>

#define debug(x)
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define PRECISION 30

using namespace std;

template<class T> int check_mod(T a, T b) { return (a % b) ? 1 : 0; }
template<class T> void maxi(T &a, T b) { a = max(a, b); return; }
template<class T> void mini(T &a, T b) { a = min(a, b); return; }

void sieve(vector<char> &prime, int range) { prime.resize(range + 1, 1); prime[0] = prime[1] = 0; for (int i = 2; i * i <= range; i++) if (prime[i]) for (int j = (i << 1); j <= range; j += i) prime[j] = 0; return; }
void sieve(vector<char> &prime, vector<int> &prime_list, int range) { prime.resize(range + 1, 1); prime[0] = prime[1] = 0; for (int i = 2; i * i <= range; i++) if (prime[i]) { prime_list.push_back(i); for (int j = (i << 1); j <= range; j += i) prime[j] = 0; } return; }
void sieve(vector<char> &prime, vector<ll> &prime_list, int range) { prime.resize(range + 1, 1); prime[0] = prime[1] = 0; for (ll i = 2; i * i <= range; i++) if (prime[i]) { prime_list.push_back(i); for (ll j = (i << 1); j <= (ll)range; j += i) prime[j] = 0; } return; }
bool is_letter(char a) { if (('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')) return true; return false; }
bool is_vowel(char a) { string vowels = "aeiouyAEIOUY"; for (char c : vowels) if (c == a) return true; return false; }
bool is_valid(int i, int j, int N, int M) { return 0 <= i && i < N && 0 <= j && j < M; }
bool all_adjacents_valid(int i, int j, int N, int M) { for (int di = -1; di <= 1; di++) for (int dj = -1; dj <= 1; dj++) if (sq(di) + sq(dj) == 1 && !is_valid(i + di, j + dj, N, M)) return false; return true; }
bool is_prime(int a) { if (a == 2) return true; if (!(a & 1) || a == 1) return false; for (int i = 3; i * i <= a; i += 2) if (!(a % i)) return false; return true; }
bool is_prime(ll a) { if (a == 2) return true; if (!(a & 1) || a == 1) return false; for (ll i = 3; i * i <= a; i += 2) if (!(a % i)) return false; return true; }
bool is_palindrome(string s) { int len = (int)s.length(); int mid = len >> 1; for (int i = 0; i < mid; i++) if (s[i] != s[len - i - 1]) return false; return true; }
bool is_palindrome(vector<char> s) { int len = (int)s.size(); int mid = len >> 1; for (int i = 0; i < mid; i++) if (s[i] != s[len - i - 1]) return false; return true; }
int gcd(int a, int b) { while (b) { int mod = a % b; a = b; b = mod; } return a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int binpow(int a, int b) { int res = 1; while (b) { if (b & 1) res *= a; a *= a; b >>= 1; } return res; }
int binpow(int a, int b, int MODULO) { int res = 1; while (b) { if (b & 1) { res *= a; res %= MODULO; } a *= a;  a %= MODULO; b >>= 1; } return res; }
ll gcd(ll a, ll b) { while (b) { ll mod = a % b; a = b; b = mod; } return a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll binpow(ll a, ll b) { ll res = 1; while (b) { if (b & 1) res *= a; a *= a; b >>= 1; } return res; }
ll binpow(ll a, ll b, ll MODULO) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= MODULO; } a *= a;  a %= MODULO; b >>= 1; } return res; }
double distance(int X1, int Y1, int X2, int Y2) { return sqrt(sq(X1 - X2) + sq(Y1 - Y2)); }
double distance(ll X1, ll Y1, ll X2, ll Y2) { return sqrt(sq(X1 - X2) + sq(Y1 - Y2)); }
double distance(double X1, double Y1, double X2, double Y2) { return sqrt(sq(X1 - X2) + sq(Y1 - Y2)); }
string binary(int N) { if (!N) return "0"; string bin = ""; while (N) { bin += '0' + (N & 1); N >>= 1; } reverse(all(bin)); return bin; }
string binary(ll N) { if (!N) return "0"; string bin = ""; while (N) { bin += '0' + (N & 1); N >>= 1; } reverse(all(bin)); return bin; }
vector<char> binary_v(int N) { if (!N) return { '0' }; vector<char> bin; while (N) { bin.push_back('0' + (N & 1)); N >>= 1; } reverse(all(bin)); return bin; }
vector<char> binary_v(ll N) { if (!N) return { '0' }; vector<char> bin; while (N) { bin.push_back('0' + (N & 1)); N >>= 1; } reverse (all(bin)); return bin; }
           
const int INF = 2147483547;           // Max int value - 100 so it will not overflow
const int MODULO = 1000000007;
const int _MODULO = 998244353;
const ll INF64 = 9223372036854775707; // Max long long value - 100 so it will not overflow
const ll MODULO64 = 1000000007;
const ll _MODULO64 = 998244353;
const double epsilon = 10e-6;
const double PI = acos(-1);

int main()                                   
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	auto t1 = chrono::high_resolution_clock::now();
    #define debug(x) cerr << #x << " = " << x << "\n";                        
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	if (n <= 3) {
		cout << n << '\n';
		return 0;
	}
	ll g = 0;
	for (ll div = 2; div * div <= n; ++div) {
		if (n % div) continue;
		g = gcd(g, div);
		while (n % div == 0) 
			n /= div;
	}
	if (n != 1) g = gcd(g, n);
	cout << g << '\n';                                                               
#ifdef LOCAL
	auto t2 = chrono::high_resolution_clock::now();
	cerr << "Running time " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
#endif
	return 0;
}