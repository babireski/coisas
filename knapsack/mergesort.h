#ifndef _mergesort_h_
	#define _mergesort_h_

	#include <stdlib.h>

	void mergesort(void* array, int n, int t, int (*compare)(const void*, const void*));
	void split(void* array, int l, int r, int t, int (*compare)(const void*, const void*));
	void merge(void* array, int l, int h, int r, int t, int (*compare)(const void*, const void*));
#endif