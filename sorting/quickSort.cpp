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

int quickSort(vector <int> *v, int s, int e, int count){
	if(s <= e){
		int pivot = partition(v, s, e);
		quickSort(v, s, pivot-1, ++count);
		quickSort(v, pivot+1, e, ++count);
	}
}

int main()
{
	/* code */
	vector <int> v;
	int n, ip, len, count=0;cin>>n;
	while(n--){
		cin>>ip;
		v.push_back(ip);
	}
	len = v.size();
	count = 0;
	quickSort(&v, 0, len-1, ++count);
	printArray(v);
	cout<<endl;
	return 0;
}