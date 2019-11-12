    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<set>
    #include<map>
    #include<cmath>
    #include<queue>

    using namespace std;

    #define int long long
    #define forn for (int i=0; i<n; i++)
    #define form for (int i=0; i<m; i++)
    #define fornj for (int j=0; j<n; j++)
    #define formj for (int j=0; j<m; j++)
    #define edge l[i]--; r[i]--; d[l[i]].push_back(r[i]); d[r[i]].push_back(l[i]);

    void write(const vector<int> &a)
    {
        for (auto i:a)
        {
            cout<<i<<" ";
        }
    }

    char t[26];
    char t1[26];
    char t2[26];

    int32_t main()
    {
        int q;
        cin>>q;
        while (q--)
        {
            int n;
            cin>>n;
            string s1,s2;
            cin>>s1>>s2;
            for (int i=0; i<26; i++)
            {
                t[i]=0;
                t1[i]=0;
                t2[i]=0;
            }
            for (int i=0; i<n; i++)
            {
                t1[s1[i]-'a']++;
                t2[s1[i]-'a']++;
            }
            bool y=true;
            for (int i=0; i<26; i++)
            {
                if ((t1[i]+t2[i])%2!=0) y=false;
            }
            if (!y)
            {
                cout<<"No"<<'\n';
                continue;
            }
            if (s1==s2)
            {
                cout<<"Yes"<<'\n';
                continue;
            }
            int pos1=-1;
            int pos2=-1;
            int cnt=0;
            for (int i=0; i<n; i++)
            {
                if (s1[i]!=s2[i])
                {
                    if (pos1!=-1) pos2=i;
                    else pos1=i;
                    cnt++;
                }
            }
            if (cnt!=2)
            {
                cout<<"No"<<'\n';
                continue;
            }
            bool can=false;
            if (s1[pos1]==s1[pos2]&&s2[pos1]==s2[pos2]) can=false;
            else can=true;
            if (can)
            {
                cout<<"No"<<'\n';
                continue;
            }
            cout<<"Yes"<<'\n';
        }
    }
