// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#include "quickSort.h"
#include "selectSort.h"
#include "insertSort.h"
#include "countSort.h"
#include "bucketSort.h"
#include "kth.h"

int main() { 
	kth::test();
	bucketSort::test();

	countSort::test();
	insertSort::test();
	selectSort::test();
	quickSort::test();

	return 0;
}