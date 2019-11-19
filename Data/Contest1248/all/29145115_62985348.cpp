#include<bits/stdc++.h>

using namespace std;

#define int long long

main(){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
                cin>>a[i];
        }
        sort(a.begin(),a.end());
        long long sum1=0,sum2=0;
        for(int i=0; i<n;i++){
                if(i<n/2){
                        sum1+=a[i];
                }
                else{
                        sum2+=a[i];
                }
        }
        cout<<sum1*sum1+sum2*sum2;
}