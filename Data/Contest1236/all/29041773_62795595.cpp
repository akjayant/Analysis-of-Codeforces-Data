#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " " << x << endl

int mat[505][505];

int main(){
	
    cout.sync_with_stdio(false);
    int n; cin >> n;
    int flag = 0, cnt = 1;
    for(int j = 1; j <= n; j++){
        if(!flag){
            for(int i = 1; i <= n; i++)
                mat[i][j] = cnt++;
        }
        else{
            for(int i = n; i >= 1; i--)
                mat[i][j] = cnt++;
        }
        flag = !flag;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

	return 0;
}
