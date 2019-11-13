#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i%2) v[j].push_back(i*n+j+1);
            else    v[n-1-j].push_back(i*n+j+1);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)  cout << v[i][j] << " \n"[j==n-1];
    }
    return 0;
}