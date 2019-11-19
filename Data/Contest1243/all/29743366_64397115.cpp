/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;                     // 10^7 should be enough for most cases
vll primes;               // compact list of primes in form of vector<long long>


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound+1;                     // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i < _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i <= _sieve_size starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);       // also add this vector containing list of primes
} }                                           // call this method in main method

bool isPrime(ll N) {                 // a good enough deterministic prime tester
  if (N < _sieve_size) return bs[N];                // now O(1) for small primes
  for (int i = 0; (i < primes.size()) && (primes[i]*primes[i] <= N); i++)
    if (N%primes[i] == 0) return false;
  return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2

// second part

set<long long> primeFactors(ll N) {   // remember: vi is vector of integers, ll is long long
  set<ll> factors;                    // vi `primes' (generated by sieve) is optional
  ll PF_idx = 0, PF = primes[PF_idx];     // using PF = 2, 3, 4, ..., is also ok
  while ((N != 1) && (PF*PF <= N)) {   // stop at sqrt(N), but N can get smaller
    while (N%PF == 0) { N /= PF; factors.insert(PF); }      // remove this PF
    PF = primes[++PF_idx];                              // only consider primes!
  }
  if (N != 1) factors.insert(N);     // special case if N is actually a prime
  return factors;         // if pf exceeds 32-bit integer, you have to change vi
}

long long solve(ll n) {
    if (isPrime(n)) {
        return n;
    }
    auto res = primeFactors(n);
    if (res.size() > 1) {
        return 1;
    }
    return *res.begin();
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int tt = clock();
    sieve(10000000);
    long long n;
    cin >> n;
    switch(n) {
        case 1: 
        cout << 1 << '\n';
        break;

        case 2:
        cout << 2 << '\n';
        break;

        default:
        cout << solve(n) << '\n';
    }



    cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
