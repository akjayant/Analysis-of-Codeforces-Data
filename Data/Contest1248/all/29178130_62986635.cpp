#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,i,j,ar[100005],hor=0,ver=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    for(i=0,j=n-1;i<j;){
        hor+=ar[j];
        j--;
        // if(i==j) break;
        ver+=ar[i];
        i++;
        // if(i==j) break;
    }
    if(i==j){
        hor+=ar[j];
    }
    cout<<hor*hor+ver*ver<<endl;
    return 0;
}