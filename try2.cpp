/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <tgmath.h>
#include <map>
#include <iterator>
using namespace std;

int main(){
    map<string, int> score, t;
    // map <int, string> ans;
    map <string, int> :: iterator sc_it;
    map <string, int> :: iterator t_it;//, t1, t2;
    // map <string, int> :: iterator max_it;
    vector <string> v;
    vector <int > sc,ti;

    int n, ip, max_score=0, ans_index = 1;
    string s;
    cin>>n;
    while(n--){
        cin>>s>>ip;
        //start
        sc_it = score.find(s);
        t_it = t.find(s);
        if(sc_it != score.end()){
            sc_it->second += 1;
        } else if(t_it != t.end()){
            t_it->second += ip;
        } else{
            score.insert(pair <string, int>(s,1));
            t.insert(pair <string, int>(s,ip));
        }
        //end
    }
    
    //

    for(sc_it = score.begin(), t_it = t.begin(); sc_it != score.end(); sc_it++){
        v.push_back(sc_it->first);
        sc.push_back(sc_it->second);
        ti.push_back(t_it->second);
        t_it++;
    }
    long int len=v.size();
    
    // cout<<"Done 1st"<<endl;
    for(long int i=0;i<len;i++){
        n = sc[i];
        s = v[i];
        max_score = ti[i];
        // cout<<endl;
        for(long int j=i;j<len;j++){
            // cout<<"n == "<<n<<endl;
            if(n<sc[j]){
                sc[i] = sc[j];
                sc[j] = n;
                ti[i] = ti[j];
                ti[j] = max_score;
                v[i] = v[j];
                v[j] = s;
            }
            if(n==sc[j]){
                if(max_score>ti[j]){
                    ti[i] = ti[j];
                    ti[j] = max_score;
                    v[i] = v[j];
                    v[j] = s;        
                }
            }
        }
    }

    for(long int i = 0; i < len;i++){
        cout<<i+1<<" "<<v[i]<<endl; 
    }
    return 0;
}