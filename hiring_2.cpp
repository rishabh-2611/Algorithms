/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tgmath.h>
#include <map>
#include <list>
#include <iterator>
using namespace std;

int main(){
    long long n, k, t, ip, i=0, max;
    vector <long long> l;
    vector <long long> pop;
    cin>>n>>k;
    // cout<<n<<k;
    t = n;
    while(t--){
        cin>>ip;
        l.push_back(ip);
        // cout<<" t = "<<t<<endl;
    }
    
    if(k%2==0){
        for(i=0; i<k-1; i++){
            pop.push_back(l[i]);
            // l.pop_front();
        }
        sort(pop.begin(), pop.end());
        max = pop[i-1];
        // l.push_front(max);
    } else {
        for(i=0; i<k-2; i++){
            pop.push_back(l[i]);
            // l.pop_front();
        }
        sort(pop.begin(), pop.end());
        max = pop[i-1];
        if(max > l[k-1]){
            l[k-1] = max;
        }
    }
    cout<<max;
    return 0;
}