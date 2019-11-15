#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int A[301][301];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1 ; i<=n*n ; i++){
        if((i-1)/n%2==1)A[(i-1)%n][(i-1)/n]=i;
        else A[n-1-(i-1)%n][(i-1)/n]=i;
    }
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=0 ; j<n ; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}