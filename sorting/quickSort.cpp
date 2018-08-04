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

int getMinimum(vector <int> v, int s, int e){
	int min_index = v[0];
	for(int i=s; i<e; i++){
		if(v[i] < v[min_index]){
			min_index = i;
		}
	}
	return min_index;
}

int quickSort(vector <int> v){
	int len = v.size();
	int pivot = v[len-1];
	for(int i=){

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

	quickSort(v);
	return 0;
}