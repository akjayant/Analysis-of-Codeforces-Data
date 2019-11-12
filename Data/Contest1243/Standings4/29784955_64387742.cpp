#include<bits/stdc++.h>

using namespace std;
const int N = 1234;


void solve(){
    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;
    vector<int> d;
    for(int i = 0 ; i <  n; i ++){
        if(a[i] != b[i]) d.push_back(i);
    }
    if(d.size()==0){
        printf("Yes\n"); return;
    }
    if(d.size()==2){
        if(a[d[0]] == a[d[1]] && b[d[0]]==b[d[1]]) {printf("Yes\n"); return ;}
    }
    printf("No\n");
}
int main(){

    int k;
    scanf("%d",&k);
    while(k--){
        solve();
    }
    return 0;
}

