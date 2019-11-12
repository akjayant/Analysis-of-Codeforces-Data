#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int x[305][305];
int main (){
	int n, i, j, crt=1;
	cin >> n;
	i = j = 1;
	for (crt=1; crt<=n*n; crt++){
        x[i][j] = crt;
        if (i % 2 == 1){
            if (j == n) i++;
            else j++;
        }
        else{
            if (j == 1) i++;
            else j--;
        }
	}
	for (j=1; j<=n; j++){
        for (i=1; i<=n; i++)
            cout << x[i][j] << " ";
        cout << "\n";
	}
	return 0;
}
