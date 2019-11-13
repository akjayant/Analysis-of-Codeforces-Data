#include<bits/stdc++.h>
using namespace std;
string s,ss;
int t,n;
vector<int> vec;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s>>ss;
        vec.clear();
        for(int i=0;i<n;i++){
            if(s[i]!=ss[i]){
                vec.push_back(i);
            }
        }
        if(vec.size()>2||vec.size()==1){
            cout<<"No"<<endl;
        }else{
           swap(s[vec[0]],ss[vec[1]]);
           if(ss==s){
               cout<<"Yes"<<endl;
           }else{
               cout<<"No"<<endl;
           }
        }
    }
    return 0;
}