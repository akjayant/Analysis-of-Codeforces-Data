#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int dif = 0;
        char a , b;
        bool flag = false;
        for (int i=0;i<n;i++){
            if (s1[i]!=s2[i]){
                if (dif == 0 ){
                    dif ++;
                    a = s1[i];
                    b = s2[i];
                }
                else if (dif == 1){
                    dif ++;
                    //cout<<s1[i]<<" "<<a<<" "<<s2[i]<<" "<<b<<endl;
                    if (s1[i]==a && s2[i]==b){
                        flag = true;
                    }
                }
                else{
                    flag = false;
                }
                //cout<<flag<<endl;
            }
        }
        if (dif == 0 ){
            flag = true;
        }
        if (flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}