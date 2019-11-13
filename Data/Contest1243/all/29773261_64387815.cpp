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
    string s,t;
    cin>>total;
    while(total--){
        vector<int>que;
        int n,cont=0;
        cin>>n;
        cin>>s>>t;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                cont++;
                que.push_back(i);
            }
        }
        if(cont==0){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(cont!=2){
            cout<<"No"<<endl;
        }else{
            if(s[que[0]]==s[que[1]] && t[que[0]]==t[que[1]]){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
