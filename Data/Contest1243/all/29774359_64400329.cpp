    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll test;
        for(cin>>test;test>0;test--) {
            int n;
            cin>>n;
            string s1,s2;
            cin>>s1>>s2;
            int st = 0;
            vector<pair<int,int> > stp;
            bool valid = true;
            for(int i = 0;i<n;i++) {
                if(s1[i]==s2[i])
                    continue;
                for(int j = i+1;j<n;j++) {
                    if(s1[j]==s1[i]) {
                        st++;
                        s1[j]=s2[i];
                        s2[i]=s1[i];
                        stp.push_back({j+1,i+1});
                        break;
                    }
                    else if(s1[i]==s2[j]) {
                        st+=2;
                        s2[j]=s1[j];
                        s1[j]=s2[i];
                        s2[i]=s1[i];
                        stp.push_back({j+1,j+1});
                        stp.push_back({j+1,i+1});
                        break;
                    }

                }
                if(s1[i]!=s2[i]) {
                    cout<<"No"<<endl;
                    valid = false;
                    break;
                }
            }
            if(!valid)
                continue;
            cout<<"Yes"<<endl;
            cout<<st<<endl;
            for(int i = 0;i<st;i++)
                cout<<stp[i].first<<" "<<stp[i].second<<endl;
        }
    }