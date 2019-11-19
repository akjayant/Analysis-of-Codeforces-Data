//in the name of god
#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main(){
    int n;
    cin>>n;
    int sum=0;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ss=0,kk=0;
    for(int i=0;i<n/2;i++){
        ss+=a[i];
    }
    for(int i=n/2;i<n;i++){
        kk+=a[i];
    }
    cout<<ss*ss+kk*kk;
}
