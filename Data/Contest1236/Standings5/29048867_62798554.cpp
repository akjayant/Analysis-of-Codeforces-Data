#include <bits/stdc++.h>

using namespace std;

vector<int> group[310];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;

    cin >> n;

    int ma = n*n, mi = 1, aux = 0;

    for(int i=1; i<=(n*n); i++){
        if(i%n==1 and i>1) aux ^= 1;
        if(aux){
            group[(i%n)+1].push_back(mi++);
        }
        else{
            group[(i%n)+1].push_back(ma--);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<group[i].size(); j++){
            cout << group[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
