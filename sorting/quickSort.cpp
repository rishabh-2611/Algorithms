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

int partition(vector <int> *v, int s, int e){
	int j = s;
	int pivot = v->at(e);
	for(int i=s; i<e; i++){
		if(j<e && v->at(i) < pivot){
			swap(v->at(i), v->at(j));
			j++;
		}
	}
	swap(v->at(e), v->at(j));
	return j;
}

int quickSort(vector <int> *v, int s, int e){
	if(s <= e){
		int pivot = partition(v, s, e);
		quickSort(v, s, pivot-1);
		quickSort(v, pivot+1, e);
	}
}

int main()
{
	/* code */
	vector <int> v;
	int n, ip, len;cin>>n;
	while(n--){
		cin>>ip;
		v.push_back(ip);
	}
	len = v.size();
	quickSort(&v, 0, len-1);
	printArray(v);
	cout<<endl;
	return 0;
}