#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=305;
vector<int> ans[max_n];
int n;
int main(){
    scanf("%d",&n);
    int now=1;
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=n;j++)ans[j].push_back(now++);
        }
        else{
            for(int j=n;j>=1;j--)ans[j].push_back(now++);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto x:ans[i])printf("%d ",x);
        printf("\n");
    }
    return 0;
}