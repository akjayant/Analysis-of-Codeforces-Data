#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string ss,tt;
        cin>>ss>>tt;
        int pos=-1;
        for(int i=0;i<ss.size();i++){
            if(ss[i]!=tt[i]){
                pos=i;
                break;
            }
        }
        if(pos==-1){
            cout<<"Yes"<<endl;
        }
        else{
            bool flag=0;
            for(int i=0;i<ss.size();i++){
                if(i!=pos && tt[pos]==tt[i] && ss[pos]==ss[i]){
                    ss[pos]=tt[pos];
                    tt[i]=ss[i];
                    break;
                }
            }
            if(ss==tt){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }

    }
}
