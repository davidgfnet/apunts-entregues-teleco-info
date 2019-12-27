

#include <iostream>

template <typename S,typename T>

class BST {
private:
	struct node {
		S key;
		T elem;
		node * l;
		node * r;
	};
	node * root;

	void insert_internal (node* &n, S key, T elem) {
		if (n == NULL) {
			n = new node;
			n->key = key;
			n->elem = elem;
			n->r = NULL; n->l = NULL;
		}else{
			if (key == n->key) {
				n->elem = elem;
			}else if (key < n->key) {
				insert_internal(n->l, key, elem);
			}else{
				insert_internal(n->r, key, elem);
			}
		}
	}
	node* minimal (node* &n) {
		if (n->l == NULL) {
			node* temp = n;
			n = n->r;
			return temp;
		}else return minimal (n->l);
	}

	void remove_internal (node* &n, S key) {
		if (n->key == key) {
			if (n->l == NULL and n->r == NULL) {
				delete n;
				n = NULL;
			}else if (n->l == NULL) {
				node* temp = n->r;
				delete n;
				n = temp;
			}else if (n->r == NULL) {
				node* temp = n->l;
				delete n;
				n = temp;
			}else{
				node* min = minimal(n->r);
				min->l = n->l;
				min->r = n->r;
				delete n;
				n = min;
			}
		}else if (key < n->key) {
			remove_internal (n->l, key);
		}else{
			remove_internal (n->r, key);
		}
	}
	T getElem_internal (node* n, S key) {
		if (n->key == key) return n->elem;
		else if (key < n->key) return getElem_internal(n->l, key);
		else return getElem_internal(n->r, key);
	}
	void destroy(node* n) {
		if (n != NULL) {
			destroy(n->l);
			destroy(n->r);
			delete n;
			n = NULL;
		}
	}
	void print_internal (node* n) {
		if (n != NULL) {
			print_internal (n->l);
			std::cout << n->key << " ";
			print_internal (n->r);
		}
	}
	void printl_internal (node* n, int h, int level) {
		if (n == NULL) return;
		if (h == level) {
			std::cout << n->key << " ";
		}else{
			printl_internal (n->l,h+1,level);
			printl_internal (n->r,h+1,level);
		}
	}
public:
	BST() { root = NULL; }
	~BST() { destroy (root); }
	void insert (S key, T elem) { insert_internal (root, key, elem); }
	void remove (S key) { remove_internal (root, key); }
	T getElem (S key) { return getElem_internal (root, key); }
	void print_tree() { print_internal(root); }
	void print_level(int level) { printl_internal(root,1,level); }
};


