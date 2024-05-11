#include "node.h"
#include <iostream>
using namespace std;

class RedBlack{
	node* root;
	int size;
	
	node* create_node(int num, node* p, bool isRed){
		node* n = new node();
		n->elem = num;
		n->left = NULL;
		n->right = NULL;
		n->parent = p;
		n->isRed = isRed;
		size++;
		return n;
	}
	
	public: RedBlack(){
		root = NULL;
		size=0;
	}
	
	void insert(int num){
		node* n = create_node(num, NULL, false);
		if(!root){
			root = n;
		}else{
			node* curr = root;
			if(n>curr){
				n->isRed = true;
				n = n->right;
			}else{
				n->isRed = true;
				n= n->left;
			}
		}		
	}
	void print(){
		cout<<"Size: "<<size<<endl;
		print("", 'Q', root);
		if(n->right!=NULL){
			print("", 'L', n->right);
		}
		
	}
	
	void print(string pre, char loc, node* n){
		if(!n){
			return;
		}
		cout<<pre<<"!--"<<loc<<": "<<n->elem;
		if(n->isRed){
			cout<<"(R)"<<endl;	
		}
		else{
			cout<<"(B)"<<endl;
		}
		print(pre+"   ", 'L', n->left);
		print(pre+"   ", 'R', n->right);
	}
};
