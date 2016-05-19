#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

struct WAM {
	WAM();
	static string tag;
	int hptr;
	int ref;
};
string WAM::tag="(none)";

WAM* HEAP[HEAPsz];
int HEAP_ALLOC=0;

WAM::WAM() {
	hptr=HEAP_ALLOC++; assert(HEAP_ALLOC<HEAPsz);
	HEAP[hptr] = this; ref=hptr;
}

WAM X;

void heap_dump() {
	for (int i=0;i<HEAP_ALLOC;i++)
		printf("%.4X:\t%s\n",i,HEAP[i]->tag.c_str());
}

int main() {
	heap_dump();
return 0; }
