#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mp[305][305];
int main(){
    int n;
    cin>>n;
    int d=0,now=1;
    for(int i=1;i<=n;i++){
        if(d==0){
            for(int j=1;j<=n;j++)
            mp[j][i]=now++;
            d=1;
        }
        else{
            for(int j=n;j>=1;j--)
            mp[j][i]=now++;
            d=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<mp[i][j]<<" ";
        cout<<endl;
    }
}