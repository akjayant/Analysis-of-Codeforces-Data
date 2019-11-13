#include <iostream>
using namespace std;

int n;
int a[300][300];

int main(){
    cin >> n;

    for(int j = 0; j < n; j = j + 2){
        for(int i = 0; i < n; i++){
            a[i][j] = (j * n + 1) + i;
        }
    }

    for(int j = 1; j < n; j = j + 2){
        for(int i = n - 1; i >= 0; i--){
            a[i][j] = (j * n + 1) + (n - i - 1);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << (j < n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
