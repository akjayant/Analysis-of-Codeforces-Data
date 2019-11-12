#include<bits/stdc++.h>
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define int long long int
#define modulo 1000000007
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n][n];
    int cnt=1;
    for(int j=0;j<n;j++){
        if(j%2==0){
            for(int i=0;i<n;i++){
                a[i][j]=cnt++;
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                a[i][j]=cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
