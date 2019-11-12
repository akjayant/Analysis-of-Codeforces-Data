#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int A[1010][1000];
int main(){
    int a,b,c,t,ans;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int x=min(c/2,b);
        b-=x;
        int y=min(b/2,a);
        cout<<(x+y)*3<<endl;
    }

    return 0;
}
