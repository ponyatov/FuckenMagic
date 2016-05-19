#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int HEAP[HEAPsz] = {1,2,3,3,4,5,6,7,8};

void heap_dump() {
	for (int i=0;i<HEAPsz;i++)
		printf("%.8X: %.8X\n",i,HEAP[i]);
}

int main() {
	heap_dump();
return 0; }
