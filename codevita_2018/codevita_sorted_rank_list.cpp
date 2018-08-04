#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

class q{
public:
    vector <string> name;
    vector <double> score;
    int head = 0;
};

int getMax(vector <double> v){
    int len = v.size();
    int max_index = 0;
    for(int i=0; i<len; i++){
        if(v[max_index] < v[i]){
            max_index = i;
        }
    }
    return max_index;
}

int main(){
    long n, m, tn, tm, index;
    vector <double> getMaxVec;
    double score;
    string name;
    cin>>n>>m;
    tn = n;
    q o[m];
    tn = 0;
    while(tn<n){
        tm = 0;
        while(tm<m){
            cin>>name>>score;
            o[tn].name.push_back(name);
            o[tn].score.push_back(score);  
            tm++;
        }
        tn++;
    }

    tn = n*m;
    while(tn--){
        tm = 0;
        while(tm<n){
            getMaxVec.push_back(o[tm].score[o[tm].head]);
            tm++;
        }
        index = getMax(getMaxVec);
        // setprecision(std::numeric_limits<long double>::digits10 + 1)
        // setprecision(10)<<
        cout<<o[index].name[o[index].head]<<" ";
        cout<<setprecision(10)<<o[index].score[o[index].head]<<endl;
        if(o[index].head < m){
            o[index].head += 1;
        }
        getMaxVec.clear();
    }

    return 0;
}