#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=500;
vector<int> v[maxn];

int main(){
     std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int m=n*n;
    int p=1,f=1;
    for(int i=1;i<=m;i++){
        v[p].push_back(i);
        if(f) p++;
        else p--;
        if(p>n){
            p=n;
            f=!f;
        }
        if(p<1){
            p=1;
            f=!f;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
