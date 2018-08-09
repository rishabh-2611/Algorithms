#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};

struct Node *newNode(int data){
	cout<<"newNode"<<endl;
	struct Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node *insert(struct Node *root, int data){
	// cout<<"insert"<<endl;
	if(root == NULL){
		root = newNode(data);
	} else if(root->data > data){
		root->right = insert(root->right, data);
	} else {
		root->left = insert(root->left, data);
	}
	return root;
}

bool search(struct Node* root, int data){
	// cout<<"search"<<endl;
	if(root != NULL && root->data != data){
		if(root->data > data){
			search(root->right, data);
		} else {
			search(root->left, data);
		}
	} else {
		return 1;
	}
	return 0;
}

bool inOrder(struct Node* root){
	// cout<<"inOrder"<<endl;
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	return true;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 5);
	insert(root, 10);
	insert(root, 15);
	inOrder(root);

	cout<<"search 5 = "<<search(root, 5)<<endl;
	cout<<"search 3 = "<<search(root, 3)<<endl;
	return 0;
}