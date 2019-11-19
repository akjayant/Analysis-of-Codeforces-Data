#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    
    cin>>n;
    int c = 0;
    long long ind = 0;
    long long t = sqrt(n);
    for(int i=2;i<=t;i++){
        if(n%i == 0)c++;
        while(n%i == 0){
            n/=i;
            ind = i;
        }
    }
    if(n > 1){
        c++;
        ind = n;
    }
    if(c == 1){
        cout<<ind<<"\n";
    }
    else{
        cout<<"1";
    }
    return 0;
}