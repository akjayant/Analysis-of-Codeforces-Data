#include<iostream>
#include<map>
#include<vector>
#include<math.h>
#include<set>
#include<queue>
#define smallMaxi 1001
#define bigMaxi 5000005
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
ll n,t,a,b;
set<ll> s;
void primeFactors(ll n) 
{ 
    
    while (n%2 == 0) 
    { 
        s.insert(2);
        n = n/2; 
    } 
  
   
    for (ll i = 3; i <= sqrt(n); i = i+2) 
    { 
        while (n%i == 0) 
        { 
            s.insert(i);
            n = n/i; 
        } 
    } 
  
    if (n > 2) 
        s.insert(n);

    
} 

int main()
{
   cin >> n;
   primeFactors(n);
   if(s.size()==1)
   {
      ll val = *(s.begin());
      cout<<val<<endl;
   }
   else
   {
      cout<<"1"<<endl;
   }
   return 0;
}