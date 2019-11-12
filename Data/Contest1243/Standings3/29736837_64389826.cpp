#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        map<char, int> m;
        for(int i=0;i<s1.length();i++)
        {
            if(m.find(s1[i])==m.end())
            {
                m[s1[i]]=1;
            }
            else
            {
                m[s1[i]]++;
            }
            if(m.find(s2[i])==m.end())
            {
                m[s2[i]]=1;
            }
            else
            {
                m[s2[i]]++;
            }
        }
        bool is_possible = true;
        for(auto c: m)
        {
            // cout<<c.second<<'\n';
            if(c.second%2!=0)
                is_possible = false;
        }
        vector<pair<int, int> > answer;
        if(!is_possible)
        {
            cout<<"No\n";
        }
        else
        {
            for(int i=0;i<s1.length();i++)
            {
                bool swap_done = false;
                if(s1[i]!=s2[i])
                {
                    // cout<<i<<'\n';
                    for(int j=i+1;j<s1.length();j++) // either we pick from this string
                    {
                        if(s1[j]==s1[i])
                        {
                            // cout<<"X";
                            swap(s1[j], s2[i]);
                            // assert(s1[i]==s2[i]);
                            answer.push_back({j+1, i+1});
                            swap_done = true;
                            break;
                        }
                    }
                    if(!swap_done)
                    {
                        for(int j=i+1;j<s2.length();j++) // or from the other string
                        {
                            if(s2[j]==s1[i])
                            {
                                swap(s2[j], s1[n-1]); 
                                swap(s1[n-1], s2[i]);
                                // assert(s1[i]==s2[i]);
                                answer.push_back({n, j+1});
                                answer.push_back({n, i+1});
                                swap_done = true;
                                break;
                            }
                        }
                    }
                }
            }
            // cout<<s1<<' '<<s2<<'\n';
            if(s1!=s2)
            {
                cout<<"No\n";
            }
            else
            {
                cout<<"Yes\n"<<answer.size()<<'\n';
                for(auto c: answer)
                {
                    cout<<c.first<<' '<<c.second<<'\n';
                }
            }
            // cout<<'\n';
        }
    }
}