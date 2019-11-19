#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n , i , x , y , ans , j;
    cin >> n;
    long long int A[n];
    for(i = 0 ; i < n ; i++){
        cin >> A[i] ;
    }
    sort(A , A + n);
    int flag = 0;
    x = y = 0 ;
    for(i = 0 , j = n - 1 ; i <= j ; flag ^= 1){
        if(flag){
            x += A[i];
            i++;
        }
        else{
            y += A[j];
            j--;
        }
    }
    ans = x * x + y * y;
    cout << ans ;
    return 0;
}