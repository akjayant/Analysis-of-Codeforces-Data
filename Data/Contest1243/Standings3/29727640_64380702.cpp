#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN=3e3+1;
const int inf = MAXN;
vector<vector<int>> trans(MAXN, vector<int>(0));

int n;
vector<pair<int , int>> edges(0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        string s,t;
        cin>>s>>t;
        int first=-1, second = -1;
        for(int j=0;j<m;j++){
            if(s[j]!=t[j] && first==-1){
                first=j;
            }
            else if(s[j]!=t[j]){
                second =j;
            }
        }
        if(second == -1){
            cout<<"No"<<endl;
            continue;
        }
        char left=s[first];
        s[first]=t[second];
        t[second]=left;
        if(s==t){
            cout<<"Yes"<<endl;
            continue;
        }
        else{
            cout<<"No"<<endl;
            continue;
        }

    }
}