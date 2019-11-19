#include <bits/stdc++.h>

using namespace std;

int ps[10000];

void init_set(int sz){
  for(int i=0; i<sz; i++) ps[i] = i;
}

int find_set(int i){
  return ps[i] == i ? i : ps[i] = find_set(ps[i]);
}

void unit_set(int i, int j){
  ps[find_set(i)] = find_set(j);
}

#define MAXP 1000010

bool prime[MAXP];
long long primes[MAXP];
int P;

void generate_primes(){
  prime[0] = prime[1] = false;
  for(int i=2; i<MAXP; i++) prime[i] = true;

  P = 0;
  for(long long i=2; i<MAXP; i++) if(prime[i]){
      for(long long j=i*i; j<MAXP; j+=i) prime[j] = false;
      primes[P++] = i;
  }
}

bool is_prime(long long n){
  if(n < MAXP) return prime[n];

  for(int i=0; primes[i]*primes[i] <= n; i++){
    if(n%primes[i] == 0) return false;
  }

  return true;
}

set<long long> prime_factors(long long n){
  set<long long> res;

  int i = 0;
  long long pf = primes[i++];

  while(pf*pf <= n){
    while(n%pf == 0){
      res.insert(pf);
      n /= pf;
    }

    if(i < P) pf = primes[i++];
  }

  if(n != 1) res.insert(n);
  return res;
}

int main(){
  generate_primes();

  long long n;
  while(scanf("%lld", &n) > 0){
    long long ans;

    if(is_prime(n)){
      ans = n;
    } else {
      set<long long> pfs = prime_factors(n);
      if(pfs.size() == 1) ans = *pfs.begin();
      else ans = 1;
    }

    printf("%lld\n", ans);
  }
}
