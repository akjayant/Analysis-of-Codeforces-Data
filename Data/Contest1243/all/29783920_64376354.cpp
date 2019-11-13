#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int n;
        cin >> n;
        int a[1010];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int z = 0;
        for (int i = n - 1; i >= 0; i--){
            z++;
            if (a[i] < z){
                z--;
                break;
            }
        }
        cout << z << endl;
    }



}
