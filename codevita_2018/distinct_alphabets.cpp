#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    vector <vector <char>> v;
    // cout<<"input string"<<endl;
    
    v = {{'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'},
        {'J', 'K', 'L'},
        {'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S'},
        {'T', 'U', 'V'},
        {'W', 'X', 'Y', 'Z'}};
    map <char, int> m;
    string s;
    double s_len=0, j=0;
    cin>>s;
    s_len = s.length();
    for(double i=0; i<s_len; i++){
        if(m.find( v[(s[i]- '0')-2][0] ) != m.end()){
            m.find( v[(s[i]- '0')-2][0] )->second += 1;
        } else {
            m.insert( pair <char, int> ( v[(s[i]- '0')-2][0] , 1));
        }
    }

    for(double i=0; i<s_len-1; i++){
        j = (s[i]- '0')%(v[i+1].size());

        if(m.find( v[(s[i+ 1]- '0')-2][j-1] ) != m.end()){
            m.find( v[(s[i]- '0')-2][j-1] )->second += 1;
        } else {
            m.insert( pair <char, int> ( v[(s[i]- '0')-2][j-1] , 1));
        }
    }

    cout<<m.size();

    return 0;
}