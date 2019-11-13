#include<iostream>
using namespace std;

int mat[301][301];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i%2==0){
                mat[n-j+1][i] = (i-1)*n+j;
            } else{
                mat[j][i] = (i-1)*n+j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}