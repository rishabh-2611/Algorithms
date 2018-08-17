#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q, a, b;
    vector<int> x, y;
    set<int> s;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> a;
        x.push_back(a);
        cin >> a;
        y.push_back(a);
    }
    
    for(int i=0; i<q; i++){
        switch(x[i]){
            case 1:
                s.insert(y[i]);
            break;
            
            case 2:
                s.erase(y[i]);
            break;

            case 3:
                set<int>::iterator itr = s.find(y[i]);

                if( itr==s.end() ){
                    cout<<"No"<<endl;
                } else {
                    cout<<"Yes"<<endl;
                }
            break;
        }
    }
    return 0;
}
