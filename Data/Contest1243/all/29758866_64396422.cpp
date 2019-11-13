#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int a[26]={0};
        bool flag = true;
        for(int i=0;i<n;i++){
            a[int(s1[i]-97)]++;
            a[int(s2[i]-97)]++;
        }
        for(int i=0;i<26;i++){
            if (a[i]%2==1){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }
        if (!flag){
            continue;
        }
        vector<int> first;
        vector<int> second;
        int count = 0;
        for(int i=0;i<n;i++){
            if (s1[i]!=s2[i]){
                for(int p=i+1;p<n;p++){
                    if (s1[p]==s1[i]){
                        first.push_back(p);
                        second.push_back(i);
                        swap(s1[p],s2[i]);
                        count++;
                        break;
                    }
                    else if(s2[p]==s1[i]){
                        first.push_back(i+1);
                        second.push_back(p);
                        first.push_back(i+1);
                        second.push_back(i);
                        count+=2;
                        swap(s1[i+1],s2[p]);
                        swap(s2[i],s1[i+1]);
                        break;
                    }
                }
            }
        }
        cout<<"YES"<<endl;
        cout<<count<<endl;
        for(int i=0;i<first.size();i++){
            cout<<first[i] + 1 <<" "<<second[i] + 1<<endl;
        }
    }
}