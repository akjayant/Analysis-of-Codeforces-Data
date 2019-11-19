#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,s1=0,s2=0;
    cin>>n;
    vector<long long>v;
    for(int i=0; i<n; i++){cin>>a;v.push_back(a);}
    sort(v.begin(),v.end());
    for(int i=0; i<n/2; i++)s1+=v[i];
    for(int i=n/2; i<n; i++)s2+=v[i];
    cout<<s1*s1+s2*s2;
}
