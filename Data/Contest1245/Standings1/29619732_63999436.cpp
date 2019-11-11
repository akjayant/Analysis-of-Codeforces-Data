#include<bits/stdc++.h>
using namespace std;
int main(void){
int n,a,b;
cin>>n;
while(n--){
cin>>a>>b;
cout<<(__gcd(a,b)==1?"Finite":"Infinite")<<endl;
}
}