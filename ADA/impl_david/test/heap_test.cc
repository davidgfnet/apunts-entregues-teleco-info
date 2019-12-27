

#include <iostream>
#include "maxheap.h"
#include "minheap.h"

using namespace std;

int main () {
	MinHeap <int,int> heap;
	heap.insert(7,0);
	heap.insert(11,0);
	heap.insert(9,0);
	heap.insert(23,0);
	heap.insert(41,0);
	heap.insert(27,0);
	heap.insert(12,0);
	heap.insert(29,0);

	heap.print_heap(); std::cout << endl;

	heap.insert(3,0);

	heap.print_heap(); std::cout << endl;

	heap.remove();

	heap.print_heap(); std::cout << endl;

}


