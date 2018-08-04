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
    map <int, string> ans;
    map <string, int> :: iterator sc_it;
    map <string, int> :: iterator t_it, t1, t2;
    map <string, int> :: iterator max_it;

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
    
    for(sc_it = score.begin(); sc_it != score.end(); sc_it++){
        cout<<sc_it->first<<" "<<sc_it->second<<endl;
    }

    //process
    max_score = score.begin() -> second;
    max_it = score.begin();
    
    for(sc_it = score.begin(); sc_it != score.end(); sc_it++){
        // cout<<"key = "<<sc_it->first<<" value = "<<sc_it->second<<endl;
    }

    if(sc_it->second == max_score){
            t1 = t.find(sc_it->first);
            t2 = t.find(max_it->first);
            if(t1->second > t2->second){//comparing times
                max_it = sc_it;
                max_score = sc_it->second;
                if(ans.find(t2->first) == ans.end()){
                    ans.insert(pair<int, string>(ans_index++, t2->second));
                    sc_it->second = 0;
                }
            } else if(t1->second == t2->second){ //time equals sorting lexicographically
                if(t1->first > t2->first){
                    ans.insert(pair<int, string>(ans_index++, t1->first));
                    ans.insert(pair<int, string>(ans_index++, t2->first));
                } else {
                    ans.insert(pair<int, string>(ans_index++, t2->first));
                    ans.insert(pair<int, string>(ans_index++, t1->first));
                }
            }
        }else if(sc_it->second > max_score){
            max_score = sc_it->second;// assigning values to max 
            max_it = sc_it;// assigning values to max 
        }


    return 0;
}