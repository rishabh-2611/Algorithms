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

bool preOrder(struct Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
	return true;
}

bool postOrder(struct Node* root){
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
	return true;
}

void printGivenLevel(struct Node* root, int h){ // a helper function for BFS
	if(root == NULL) return;
	if(h==1) cout<<root->data<<" ";
	else if(h > 1)
		printGivenLevel(root->left, h-1);
		printGivenLevel(root->right, h-1);

}

bool bfs(struct Node *root){
	for(int h=1; h<5; h++){
		printGivenLevel(root, h);
	}
}

struct Node *findMin(struct Node* root){
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node *findMax(struct Node *root){
	while(root->right != NULL)root = root->right;
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
		} else if(root->right == NULL){// right child not present
			struct Node* temp = root;
			root = root->left;
			delete temp;
		} else if(root->left == NULL){//left child not present
			struct Node* temp = root;
			root = root->right;
			delete temp;
		}
	}
	return root;
}

int max(int a, int b){
	return (a>b)?a:b;
}

int findHeight(struct Node *root){
	if(root == NULL)
		return -1;
	return max(findHeight(root->left), findHeight(root->right))+1;
}

int main()
{
	Node *root = NULL;

	root = insert(root, 40);
	insert(root, 30);
	insert(root, 60);
	insert(root, 20);
	insert(root, 15);
	insert(root, 25);
	insert(root, 35);
	// inOrder(root);
	cout<<"BFS - "<<endl;
	bfs(root);
	cout<<endl;

	cout<<"search 15 = "<<search(root, 15)<<endl;
	cout<<"search 3 = "<<search(root, 3)<<endl;
	cout<<endl;

	root = Delete(root, 15);
	cout<<"Tree after deletion of 15 - ";
	cout<<"InOrder - "<<endl;
	inOrder(root);
	cout<<endl;

	root = Delete(root, 60);
	cout<<"Tree after deletion of 60 - ";
	cout<<"InOrder - "<<endl;
	inOrder(root);
	cout<<"BFS - "<<endl;
	bfs(root);
	cout<<endl;

	cout<<"Height "<<endl<<findHeight(root)<<endl;

	return 0;
}