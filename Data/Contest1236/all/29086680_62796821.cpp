#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(i&1){
                v[n-j].push_back(i*n+j);
            }
            else{
                v[j-1].push_back(i*n+j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int x:v[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}