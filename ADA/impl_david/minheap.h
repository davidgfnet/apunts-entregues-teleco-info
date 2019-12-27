

#include <iostream>
#include <vector>

template <typename S,typename T>

class MinHeap {
private:
	struct node {
		S key;
		T elem;
	};
	std::vector <node> heap;

	void flotar(int pos) {
		while (heap[pos].key < heap[pos/2].key and pos > 1) {
			node temp = heap[pos];
			heap[pos] = heap[pos/2];
			heap[pos/2] = temp;
			pos = pos / 2;
		}
	}
	void hundir(int pos) {
		while (pos*2 <= heap.size()-1) {
			int pos2 = pos*2;
			if (heap[pos2].key > heap[pos2+1].key) pos2++;
			if (pos2 >= heap.size()-1) break;
			if (heap[pos].key > heap[pos2].key) {
				node temp = heap[pos];
				heap[pos] = heap[pos2];
				heap[pos2] = temp;
			}else break;
			pos = pos2;
		}	
	}
public:
	MinHeap () { node temp; heap.push_back(temp); }
	void insert (S key, T elem) {
		node temp;
		temp.key = key;
		temp.elem = elem;
		heap.push_back (temp);
		flotar(heap.size()-1);
	}
	void remove () {
		heap[1] = heap[heap.size()-1];
		heap.pop_back();
		hundir(1);
	}
	T getMin () { return heap[1]; }
	void print_heap() { for (int i = 1; i < heap.size(); i++) std::cout << heap[i].key << " "; }
};


