//
//  main.cpp
//  Contests
//
//  Created by Giga Khizanishvili on 6/11/19.
//  Copyright © 2019 Giga Khizanishvili. All rights reserved.
//


// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* Defines */
#define scanVector(v) for(int i = 0; i < v.size() ; i++){ cin>>v[i]; }
#define printVector(v) for(int i = 0; i < (int)v.size() ; i++){ cout<<v[i]<<" "; }
#define printlnVector(v) for(int i = 0; i < v.size(); i++){ cout<<v[i]<<endl; }
#define scanGrid(g) for(int i = 0; i < g.size(); i++){ for(int j = 0; j < g[i].size(); j++){ cin >> g[i][j]; } }
#define printGrid(g) for(int i=0; i<g.size(); i++){for(int j=0; j<g[i].size(); j++)cout<<g[i][j]<<" "; cout<<endl;}

/* Constants */
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;
const double PI = 3.141592653589793238462643383;

/* __________________________________________________________________________________ */

int main()
{   ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    
    int nTests; cin >> nTests;
    while(nTests--){
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        int ind1 = -1;
        int ind2 = -1;
        bool failed = false;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                if(ind1 == -1){
                    ind1 = i;
                } else if(ind2 == -1){
                    ind2 = i;
                } else {
                    cout << "No" << endl;
                    failed = true;
                    break;
                }
            }
        }
        if(failed) continue;
        
        if(ind1 != -1 && ind2 == -1){
            cout << "No" << endl;
        } else {
            if(s1[ind1] == s1[ind2] && s2[ind2] == s2[ind1]){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}
