// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#include "src/quickSort.h"
#include "src/selectSort.h"
#include "src/insertSort.h"
#include "src/countSort.h"
#include "src/bucketSort.h"
#include "src/kth.h"

int main() { 
	kth::test();
	bucketSort::test();

	countSort::test();
	insertSort::test();
	selectSort::test();
	quickSort::test();

	return 0;
} 