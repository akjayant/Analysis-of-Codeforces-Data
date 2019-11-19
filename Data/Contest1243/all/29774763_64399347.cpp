#include<bits/stdc++.h>
#define int long long
using namespace std;
vector <int> p;
void primes(int n){
    if(n%2==0)
        p.push_back(2);
    while (n%2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
         if(n%i==0)
        p.push_back(i);
        while (n%i == 0)
        {
            n = n/i;
        }
    }
        if(n>2)
        p.push_back(n);
}
main(){
int n;
cin>>n;
primes(n);
n=p.size();
if(n==1){
    cout<<p[0];
}
else{
    cout<<1;
}
 return 0;
}
