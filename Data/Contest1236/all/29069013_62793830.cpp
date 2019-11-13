#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pi;
 
ll mod = 1e9 + 7;

bool comp(pi a, pi b){
    return a.F < b.F || (a.F == b.F && a.S < b.S);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    int n;
    cin >> n;
    vector < vector <int> > arr(n);
    int low = 1;
    int high = n*n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i%2){
                arr[j].push_back(high--);
            }
            else{
                arr[j].push_back(low++);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}