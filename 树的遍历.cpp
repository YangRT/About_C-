#include<iostream>
#include<stack>
#include<list>
using namespace std;
typedef struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int value;
}TreeNode,*Tree;

void createTree(Tree &T){
	int c;
	cin>>c;
	if(c == -1){
		T = NULL;
	}else{
		T = new TreeNode;
		T->value = c;
		createTree(T->left);
		createTree(T->right);
	}
	
} 
list<int> preTraversal(Tree root){
	stack<Tree> stack;
	list<int> ans;
	if(root == NULL) return ans;
	stack.push(root);
	while(!stack.empty()){
		root = stack.top();
		stack.pop();
		cout<<root->value<<" "<<endl;
		ans.push_back(root->value);
		if(root->right != NULL) stack.push(root->right);
		if(root->left != NULL) stack.push(root->left);
	}
}

list<int> inorderTraversal(Tree root){
	stack<Tree> stack;
	list<int> ans;
	Tree cur = root;
	while(cur != NULL && !stack.empty()){
		if(cur != NULL){
			stack.push(cur);
			cur = cur->left;
		}else{
			cur = stack.top();
			stack.pop();
			ans.push_back(cur->value);
			cur = cur->right;
		}
	}
	return ans;
}

list<int> postTraversal(Tree root){
	list<int> ans;
	stack<Tree> stack;
	if(root == NULL) return ans;
	stack.push(root);
	while(!stack.empty()){
		Tree t = stack.top();
		stack.pop();
		if(t->left != NULL) stack.push(t->left);
		if(t->right != NULL) stack.push(t->right);
		ans.push_front(t->value);
	}	
	return ans;
}

int main(){
	Tree T;
	createTree(T);
	preTraversal(T);
	return 0;
} 
