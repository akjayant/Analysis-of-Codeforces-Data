#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
    
        int s=0,flag = false;
        for(int i=n-1;i>=0;i--){
            if (a[i]<n-i){
                cout<<s<<endl;
                flag = true;
                break;
            }
            s++;
        }
        if (!flag)
            cout<<s<<endl;
    }
}