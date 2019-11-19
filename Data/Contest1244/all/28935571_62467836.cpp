#include<bits/stdc++.h>
using namespace std;

void tc(){
    int n;
    char str[1005];
    cin>>n>>str;
    int m=n;
    for(int i=0; i<n; ++i){
        if(str[i]=='1'){
            m=max(m,2*max(i+1,n-i));
        }
    }
    cout<<m<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) tc();
    return 0;
}
