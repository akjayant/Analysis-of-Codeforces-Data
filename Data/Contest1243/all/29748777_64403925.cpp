#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{


    int t;
    cin>>t;
    while(t--)
    {
        int n,flag = 0;
        cin>>n;
        string str1,str2;
        cin>>str1>>str2;
        vector<pair<int,int> >vc;
        for(int i = 0; i< n; i++)
        {
            if(str1[i] == str2[i]) continue;
            char ch =  str1[i],ck = 0;
            for(int j = i + 1; j < n; j++)
            {
                if(str1[j] == ch)
                {
                    vc.push_back({j+1,  i+1 });
                    swap(str1[j],str2[i]);
                    ck = 1;
                    break;
                }
            }
            if(ck == 0)
            {
                for(int j = i + 1; j < n; j++)
                {
                    if(str2[j] == ch)
                    {
                        vc.push_back({j+1,  j+1 });
                         swap(str1[j],str2[j]);
                        vc.push_back({j+1,  i+1 });
                         swap(str1[j],str2[i]);
                        ck = 1;
                        break;
                    }
                }
            }
            if(ck == 0) {
             //   cout<<"pos = "<<i<<endl;
                    flag = 1; break;}
        }
        if(flag) cout<<"No"<<endl;
        else
        {
            cout<<"YES"<<endl;
            int sz = vc.size();
            cout<<sz<<endl;
            for(int i = 0; i< sz; i++)
                cout<<vc[i].first<<" "<<vc[i].second<<endl;
        }
    }
    return 0;
}
