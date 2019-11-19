#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<utility>
#include<set>
using namespace std;
int main()
{
long long int n;
cin>>n;
long long int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
sort(a,a+n);
long long int ls=0,fs=0;
for(int i=0;i<n/2;i++)
{
 ls+=a[i];   
}
for(int i=n/2;i<n;i++)
{
   fs+=a[i]; 
}
long long int x=fs*fs+ls*ls;
cout<<x;
return 0;
}
