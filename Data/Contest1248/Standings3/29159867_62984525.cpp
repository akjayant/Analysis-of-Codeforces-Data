#include<bits/stdc++.h>
using namespace std;
int arr[100010];

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int hlf = n/2;

    long long x=0,y=0;

    for(int i=0;i<hlf;i++){
        x+=arr[i];
    }

    for(int i=hlf;i<n;i++){
        y+=arr[i];
    }

    cout<<x*x+y*y;

    
}