#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        vector<pair<char,char>>vec;
        int n;
        cin>>n;
        string str1,str2;
        cin>>str1>>str2;
        for(int i = 0 ; i < n; i++)
            if(str1[i] != str2[i])
                vec.push_back({str1[i],str2[i]});
                              if(vec.size()>2 || vec.size() == 1)  cout<<"No"<<endl;
                              else
                              {
                                  if(vec.size() == 0)
                                  cout<<"Yes"<<endl;
                                  else
                                  {
                                   //   swap(vec[0].first,vec[0].second);
                                      if(vec[0] == vec[1])
                                      cout<<"Yes"<<endl;
                                      else
                                      cout<<"No"<<endl;
                                  }
                              }
            }
}
