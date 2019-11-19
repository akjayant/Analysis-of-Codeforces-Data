#include <bits/stdc++.h>

using namespace std;
#define lli long long int
#define vi vector <lli>
#define pll pair<lli, lli>
#define x first
#define y second
#define mp make_pair
#define f(i,a, n) for (lli i = a; i < n; i++)

#define inf 9999999291299
#define pb push_back

lli M = 1000000007; 

// bool operator < (pll a, pll b)
// {
//     if (a.first != b.first)
//         return (a.first < b.first);
//     else 
//         return (a.second < b.second);

// }


// vi make_sieve (lli n)
// {
//     vi sieve (n+1, 0);
//     lli rt = sqrt(n);
//     for (int i = 2; i*i <= n; i++)
//         if (i > 1 && sieve[i] == 0)
//         {
//             lli temp = 2*i;
//             while (temp <= n)
//             {   
//                 sieve [temp]++;
//                 temp += i;
//             }
//         }

//     vi primes;
//     for (lli j = 2; j <= n; j++)
//         if (sieve[j] == 0)
//             primes.push_back(j);

//     return primes;
//     //return sieve;
// }

lli power(lli x, unsigned lli y, unsigned lli m) 
{ 
    if (y == 0) 
        return 1; 
    lli p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
  
// // Function to return gcd of a and b 
// lli gcd(lli a, lli b) 
// { 
//     if (a == 0) 
//         return b; 
//     return gcd(b%a, a); 
// }
// int nCrModp(int n, int r, int p) 
// { 
//     // The array C is going to store last row of 
//     // pascal triangle at the end. And last entry 
//     // of last row is nCr 
//     int C[r+1]; 
//     memset(C, 0, sizeof(C)); 
  
//     C[0] = 1; // Top row of Pascal Triangle 
  
//     // One by constructs remaining rows of Pascal 
//     // Triangle from top to bottom 
//     for (int i = 1; i <= n; i++) 
//     { 
//         // Fill entries of current row using previous 
//         // row values 
//         for (int j = min(i, r); j > 0; j--) 
  
//             // nCj = (n-1)Cj + (n-1)C(j-1); 
//             C[j] = (C[j] + C[j-1])%p; 
//     } 
//     return C[r]; 
// } 

// set <lli> getFactors (lli n) {
//     // get a set of factors of n including 1 and n, O(root(n)) complexity;
//     set <lli> Factors;
//     for (lli i = 1; i * i <= n; i++)
//         if (n%i == 0) {
//             Factors.insert(i);
//             Factors.insert(n / i);
//         }

//     return Factors;
// }
// lli CeilIndex(std::vector<lli>& v, lli l, lli r, lli key) 
// { 
//     while (r - l > 1) { 
//         lli m = l + (r - l) / 2; 
//         if (v[m] >= key) 
//             r = m; 
//         else
//             l = m; 
//     } 
  
//     return r; 
// } 
  
// lli LongestIncreasingSubsequenceLength(std::vector<lli>& v) 
// { 
//     if (v.size() == 0) 
//         return 0; 
  
//     std::vector<lli> tail(v.size(), 0); 
//     lli length = 1; // always pollis empty slot in tail 
  
//     tail[0] = v[0]; 
//     for (size_t i = 1; i < v.size(); i++) { 
  
//         // new smallest value 
//         if (v[i] < tail[0]) 
//             tail[0] = v[i]; 
  
//         // v[i] extends largest subsequence 
//         else if (v[i] > tail[length - 1]) 
//             tail[length++] = v[i]; 
  
//         // v[i] will become end candidate of an existing 
//         // subsequence or Throw away larger elements in all 
//         // LIS, to make room for upcoming grater elements 
//         // than v[i] (and also, v[i] would have already 
//         // appeared in one of LIS, identify the location 
//         // and replace it) 
//         else
//             tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
//     } 
  
//     return length; 
// }
 vector <vi> Adj;

// string mdfs (lli node) {
//     string s = "0";
//     s[0] += w[node];

//     if (adj[node].size() == 0) {
//         return s; 
//     }
    
//     multiset <string> v;
//     string temp;
//     // if (node != 0)
//     //     adj[node].erase(par[node]);
//     for (auto e: adj[node]) {
//         adj[e].erase(node);
//        // par[e] = node;
//         temp = mdfs (e);
//         v.insert(temp);
//      //   cout << e << " " << temp << " " << endl;
//     }

//     string t = s;
    
//     for (auto e : v) {
//         t+=e;
//     }

//     //t+=s; 

//     return t;

// }







// lli mlog (lli a, lli b) {
//     lli ans = 0;
//     while (a >= b) {
//         ans++;
//         a/=b;
//     }

//     return ans;
// }

// vi mdInv (100002, 1);

vi fact (100002, 1);
vi factInv (100002, 1);

void solvetest() {
    lli n, m;
    cin >> n >> m;
    lli a = 0;
    lli b = 0;
    lli n2 = n/2;
    lli m2 = m/2;
    f (i, 1, n2+1) {
        a += ((((((((fact[n-i])%M)*factInv[i])%M)))*factInv[n-2*i]%M))%M;
        // cout << a << endl;
    }
    f (i, 1, m2+1) {
        b += ((((((((fact[m-i])%M)*factInv[i])%M)))*factInv[m-2*i]%M))%M;
    } 

    // cout << a << " " << b << endl;

    cout << (2 * (a + b + 1))%M << endl;
}



int main (void)
{
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 1;
    // cin >> t;
    f (i, 1, 100002) {
        fact[i] = (fact[i-1] * i)%M;
        factInv[i] = power(fact[i], M-2, M);
    }
    while (t--) {
       solvetest();

    }

}