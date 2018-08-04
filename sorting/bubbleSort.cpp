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

void swap(int *a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int bubbleSort(vector <int> v){
	int len = v.size();
	for(int i=0; i<len-1; i++){
		for(int j=0; j<len-i-1; j++){
			if(v[j] > v[j+1]){
				swap(v[j+1], v[j]);
			}
		}
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

	bubbleSort(v);
	return 0;
}