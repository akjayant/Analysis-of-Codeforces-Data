#include<bits/stdc++.h>
using namespace std;
vector<int> *graph;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mxm=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            mxm=max(mxm, max(i+1,n-i));
        }
    }
    cout<<max(n,2*mxm)<<"\n";
}

}