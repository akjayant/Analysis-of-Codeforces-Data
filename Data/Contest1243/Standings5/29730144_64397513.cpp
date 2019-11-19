#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
using namespace std;

//global here

ll arr[100000]={0};
//function here
// Function to find the smallest divisor 
ll smallestDivisor(ll n) 
{ 
    // if divisible by 2 
    if (n % 2 == 0) 
        return 2; 
    // iterate from 3 to sqrt(n) 
    for (int i = 3; i  <= sqrt(n); i += 2) { 
        if (n % i == 0) 
            return i; 
    } 
    return n; 
} 
long long maxPrimeFactors(long long n) 
{ 
    long long maxPrime = 1;   
    
    while (n % 2 == 0) { 
        maxPrime = 2; 
        n >>= 1; 
    }  
    for (int i = 3; i <= sqrt(n); i += 2) { 
        while (n % i == 0) { 
            maxPrime = i; 
            n = n / i; 
        } 
    } 

    if (n > 2) 
        maxPrime = n; 
  
    return maxPrime; 
} 
//main here
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	ll n;
	cin>>n;
	ll ans = smallestDivisor(n);
	ll ans2 = maxPrimeFactors(n);
	if(ans != ans2){
		cout<<1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
