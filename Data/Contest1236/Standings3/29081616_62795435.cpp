#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];
    int x = n*n;
    for(int i = 0;i<n;i+=2){
        for(int j = 0;j<n;j++){
            arr[j][i] = x--;
        }
        if(i+1 < n)
            for(int j = n-1;j>=0;j--){
                arr[j][i+1] = x--;
            }
    }
    for(int i = 0;i<n;i++ , cout<<'\n')
        for(int j = 0; j < n ; j++)
            cout<<arr[i][j]<<' ';
    return 0;
}