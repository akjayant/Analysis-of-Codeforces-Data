#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,i,sum=0,x;
    cin>>n;
    vector <long long int> a(n,0);
    for (i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    };
    sort(a.begin(),a.end());
    x=0;
    for (i=0; i<n/2; i++)
        x+=a[i];
    cout<<x*x+(sum-x)*(sum-x);
    return 0;
}
