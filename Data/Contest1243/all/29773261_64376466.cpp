#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int total;
    int num[1005];
    cin>>total;
    while(total--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
        for(int i=n;i>=1;i--){
            int cont=0;
            for(int j=1;j<=n;j++){
                if(num[j]>=i){
                    cont++;
                }
            }
            if(cont>=i){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
