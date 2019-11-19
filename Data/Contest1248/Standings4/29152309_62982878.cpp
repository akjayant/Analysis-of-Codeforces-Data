#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2==0){
        long long suml=0,sumr=0;
        for(int i=0;i<n;i++){
            if(i<n/2)
                suml+=a[i];
            else
                sumr+=a[i];
        }
                cout<<suml*suml+sumr*sumr<<endl;

    }
    else{
        long long suml=0,sumr=0;
        for(int i=0;i<n;i++){
            if(i<=n/2-1)
                suml+=a[i];
            else
                sumr+=a[i];
        }
        cout<<suml*suml+sumr*sumr<<endl;
    }
    return 0;
}
