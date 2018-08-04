#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void printArray(vector <int> v){
	vector <int> :: iterator i;
	for(i = v.begin(); i!= v.end(); i++){
		cout<<*i<<" ";
	}
}

int insertionSort(vector <int> v){
	int len = v.size();
	for(int i=1; i<len; i++){
		int j = i-1;
		int key = v[i];

		while(j>=0 && v[j] > key){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
	
	printArray(v);
}

int main()
{
	/* code */
	vector <int> v;
	int n, ip;cin>>n;
	while(n--){
		cin>>ip;
		v.push_back(ip);
	}

	insertionSort(v);
	return 0;
}