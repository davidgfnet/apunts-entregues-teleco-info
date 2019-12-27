

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


template <typename S,typename T>

class AVL {
private:
	struct node {
		S key;
		T elem;
		node * l;
		node * r;
		int h;
	};
	node * root;

	int max (int a, int b) { if (a>b) return a; else return b; }
	int hcalc (node* n) {
		if (n != NULL) {
			if (n->l != NULL and n->r != NULL) return max(n->l->h, n->r->h) + 1;
			else if (n->l != NULL) return n->l->h + 1;
			else if (n->r != NULL) return n->r->h + 1;
			else return 1;
		}else return 0;
	}
	void LL (node* &x) {
		node* y = x->l;
		x->l = y->r;
		y->r = x;
		x = y;
		x->r->h = hcalc(x->r);
		x->h = hcalc(x);
	}
	void RR (node* &x) {
		node* y = x->r;
		x->r = y->l;
		y->l = x;
		x = y;
		x->l->h = hcalc(x->l);
		x->h = hcalc(x);
	}
	void LR (node* &x) {
		RR(x->l);
		LL(x);
	}
	void RL (node* &x) {
		LL(x->r);
		RR(x);
	}

	void insert_internal (node* &n, S key, T elem) {
		if (n == NULL) {
			n = new node;
			n->key = key;
			n->elem = elem;
			n->r = NULL; n->l = NULL;
			n->h = 1;
		}else{
			if (key == n->key) {
				n->elem = elem;
			}else if (key < n->key) {
				insert_internal(n->l, key, elem);
				n->h = hcalc(n);
				if (n->h > 2) {
					if (hcalc(n->l) - hcalc(n->r) == 2) {
						if (n->l->key > key) LL(n);
						else LR(n);
					}
				}
			}else{
				insert_internal(n->r, key, elem);
				n->h = hcalc(n);
				if (n->h > 2) {
					if (hcalc(n->r) - hcalc(n->l) == 2) {
						if (n->r->key < key) RR(n);
						else RL(n);
					}
				}
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

	void balance_l (node* &n) {
		if (hcalc(n->r) - hcalc(n->l) == 2) {
			if (hcalc(n->r->l) - hcalc(n->r->r) == 1) RL(n);
			else RR(n);
		}
	}
	void balance_r (node* &n) {
		if (hcalc(n->l) - hcalc(n->r) == 2) {
			if (hcalc(n->l->r) - hcalc(n->l->l) == 1) LR(n);
			else LL(n);
		}		
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
				if (n->r != NULL) n->r->h = hcalc(n->r);
				if (n->l != NULL) n->l->h = hcalc(n->l);
				n->h = hcalc(n);
			}
		}else if (key < n->key) {
			remove_internal (n->l, key);
			n->h = hcalc(n);
			balance_l(n);
		}else{
			remove_internal (n->r, key);
			n->h = hcalc(n);
			balance_r(n);
		}
	}
	bool isElement_internal (node* n, S key) {
		if (n == NULL) return false;
		if (n->key == key) return true;
		else if (key < n->key) return isElement_internal(n->l, key);
		else return isElement_internal(n->r, key);
	}
	T * getElem_internal (node* n, S key) {
		if (n->key == key) return &n->elem;
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
	void Print_internal (node* n, T elem) {
		if (n == NULL) return;
		Print_internal(n->l,elem);
		if (n->elem == elem) cout << n->key << endl;
		Print_internal(n->r,elem);
	}
	void PrintInv_internal (node* n, T elem) {
		if (n == NULL) return;
		Print_internal(n->r,elem);
		if (n->elem == elem) cout << n->key << endl;
		Print_internal(n->l,elem);
	}

public:
	AVL() { root = NULL; }
	~AVL() { destroy (root); }
	void insert (S key, T elem) { insert_internal (root, key, elem); }
	void remove (S key) { remove_internal (root, key); }
	T * getElemgetElem (S key) { return getElem_internal (root, key); }
	bool isElement (S key) { return isElement_internal (root, key); }
	void Print (T elem)  { Print_internal (root,elem); }
	void PrintInv (T elem)  { PrintInv_internal (root,elem); }
};



int main () {
	AVL <string,bool> vec;
	string p;
	while (cin >> p) {
		bool esta = vec.isElement(p);
		if (not esta) {
			vec.insert( p,true);
		}else{
			bool * c = vec.getElemgetElem (p);
			*c = not *c;
		}
	}
	vec.Print(true);
	cout << "--------------------" << endl;
	vec.PrintInv(false);
}



