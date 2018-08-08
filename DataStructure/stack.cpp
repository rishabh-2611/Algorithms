#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Stack{
	int top=-1;
public:
	int a[1000];
	bool push(int);
	int pop();
	void display();
	bool isEmpty();
};

bool Stack :: isEmpty(){
	if(top == -1)
		return true;
	else
		return false;
}

bool Stack :: push(int data){
	top++;
	a[top] = data;
}

int Stack :: pop(){
	if(!isEmpty()){
		top--;
		return a[top+1];
	} else {
		return false;
	}
}

void Stack :: display(){
	if(isEmpty())
		return;
	for(int i=0; i<=top; i++){
		cout<<a[i]<<"->";
	}
}

int main()
{
	int choice, ip;
	Stack s;
	while(1){
		cout<<"\nStack\n1.Push Element\n2.Pop Element\n3.Display\n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to be pushed\n";
				cin>>ip;
				s.push(ip);
				s.display();
			break;
			case 2:
				ip = s.pop();
				if(ip != false){
					cout<<"stack is empty nothing to remove"<<endl;
					break;
				}else{
					cout<<"Popped "<<ip<<endl;
				}
				s.display();
			break;

			case 3:
				s.display();
			break;

			default:
			cout<<"\n";
			break;
		}
	}
	return 0;
}