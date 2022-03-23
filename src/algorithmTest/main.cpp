#include "quickSort.h"
#include "selectSort.h"
#include "insertSort.h"
#include "countSort.h"
#include "bucketSort.h"


int main() {
	bucketSort::test();

	countSort::test();
	insertSort::test();
	selectSort::test();
	quickSort::test();

	return 0;
}