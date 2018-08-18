#include <iostream>
using namespace std;

class MinHeap{
	int *harr;
	int capacity;
	int heapSize;
public:
	MinHeap(int c);
	void heapify(int i);
	void swap(int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	int parent(int i){ return (i/2)-1; }
	int left(int i){ return (i*2+1); }
	int right(int i){ return (i*2+2); }

	int extractMin();
	void decreaseKey(int i, int value);
	int getMin(){ return harr[0]; }
	void deleteKey(int i);
	void insertKey(int k);
};

MinHeap :: MinHeap(int c){
	heapSize = 0;
	capacity = c;
	harr = new int[c];
}

void MinHeap :: heapify(int i){
	cout<<"heapify"<<endl;
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heapSize && harr[l] < harr[i])
		smallest = l;
	if(r < heapSize && harr[r] < harr[i])
		smallest = r;
	if(smallest != i){
		swap(&harr[i], &harr[smallest]);
		heapify(smallest);
	}
}

int MinHeap :: extractMin(){
	cout<<"Extract Min"<<endl;
	if(heapSize <= 0){
		return 1000000;
	}
	if(heapSize == 1){
		return harr[0];
	}
	int temp = harr[0];
	harr[0] = harr[heapSize-1];
	heapSize--;
	heapify(0);
}

void MinHeap :: insertKey(int k){
	cout<<"Insert Key"<<endl;
	if(heapSize == capacity){
		cout<<"Heap overflow\n";
		return;
	}
	heapSize++;
	int i = heapSize-1;
	harr[i] = k;

	while(i>=0 && harr[parent(i)] > harr[i]){
		swap(&harr[parent(i)], &harr[i]);
		i = parent(i);
	}
}

void MinHeap :: decreaseKey(int i, int k){
	cout<<"Decrease Key"<<endl;
	
	harr[i] = k;
	while(i>=0 && harr[parent(i)] > harr[i]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap :: deleteKey(int i){
	cout<<"Delete Key"<<endl;
	decreaseKey(i, 0);
    extractMin();
}

int main()
{
	/* code */
	MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
	return 0;
}