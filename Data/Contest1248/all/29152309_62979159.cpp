#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    long long ev=0,od=0;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        if(a%2==0)
        ev++;
        else
        od++;
    }
    int m;
    cin>>m;
    long long ev1=0,od1=0;
    for(int i=0;i<m;i++){
        long long a;
        cin>>a;
        if(a%2==0)
        ev1++;
        else
        od1++;
    }
    long long ans=(ev*ev1)+(od*od1);
    cout<<ans<<endl;
    }
    return 0;
}
