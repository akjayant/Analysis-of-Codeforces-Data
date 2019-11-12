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
    int letter[30];
    cin>>total;
    string s,t;
    while(total--){
        int n;
        vector<int>ss,tt;
        cin>>n;
        cin>>s>>t;

        if(s==t){
            cout<<"Yes"<<endl;
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
            continue;
        }

        memset(letter,0,sizeof(letter));
        for(int i=0;i<n;i++){
            letter[s[i]-'a'+1]++;
            letter[t[i]-'a'+1]++;
        }
        bool flag=true;
        for(int i=1;i<=26;i++){
            if(letter[i]%2==1){
                flag=false;
                break;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        int cont=0;
        for(int i=0;i<n;i++){
            if(s[i]==t[i]){
                cont++;
                ss.push_back(i);
                tt.push_back(i);
            }else{
                bool book=false;
                for(int j=i+1;j<n;j++){
                    if(s[i]==s[j]){
                        cont++;
                        book=true;
                        ss.push_back(j);
                        tt.push_back(i);
                        char temp=s[j];
                        s[j]=t[i];
                        t[i]=temp;
                        break;
                    }
                }
                if(book) continue;
                for(int j=i+1;j<n;j++){
                    if(s[i]==t[j]){
                        cont+=2;
                        ss.push_back(j);
                        tt.push_back(j);
                        char temp=s[j];
                        s[j]=t[j];
                        t[j]=temp;
                        ss.push_back(j);
                        tt.push_back(i);
                        temp=s[j];
                        s[j]=t[i];
                        t[i]=temp;
                        break;
                    }
                }
            }
        }
        cout<<cont<<endl;
        for(int i=0;i<ss.size();i++){
            cout<<ss[i]+1<<" "<<tt[i]+1<<endl;
        }
    }
    return 0;
}
