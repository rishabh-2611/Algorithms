#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};

struct Node *newNode(int data){
	struct Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node *insert(struct Node *root, int data){
	if(root == NULL){
		root = newNode(data);
	} else if(root->data < data){
		root->right = insert(root->right, data);
	} else {
		root->left = insert(root->left, data);
	}
	return root;
}

bool search(struct Node* root, int data){
	if(root != NULL && root->data != data){
		if(root->data < data){
			search(root->right, data);
		} else if(root->data > data){
			search(root->left, data);
		}
	} else {
		return 1;
	}
		return 0;
}

bool inOrder(struct Node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	return true;
}

struct Node *findMin(struct Node* root){
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node *Delete(struct Node* root, int data){
	if(root == NULL){//Case 1: root == NULL
		return root;
	} else if(data > root->data){//Case 3.1: data is greater than root
			root->right = Delete(root->right, data);
	} else if(data < root->data){//Case 3.2:  data is less than root
		root->left = Delete(root->left, data);
	} else { // Case 4: Found data
		if(root->left != NULL && root->right != NULL){// both child
			struct Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		} else if(root->right == NULL){
			struct Node* temp = root;
			root = root->left;
			delete temp;
		} else if(root->left == NULL){
			struct Node* temp = root;
			root = root->right;
			delete temp;
		}
	}
	return root;
}

int main()
{
	Node *root = NULL;

	root = insert(root, 5);
	insert(root, 10);
	insert(root, 15);
	inOrder(root);
	cout<<endl;

	cout<<"search 15 = "<<search(root, 15)<<endl;
	cout<<"search 3 = "<<search(root, 3)<<endl;
	cout<<endl;

	root = Delete(root, 15);
	cout<<"Tree after deletion of 15 - ";
	inOrder(root);
	cout<<endl;

	root = Delete(root, 5);
	cout<<"Tree after deletion of 5 - ";
	inOrder(root);
	cout<<endl;

	return 0;
}