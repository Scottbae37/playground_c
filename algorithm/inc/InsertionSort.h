#ifndef PLAYGROUND_INSERTIONSORT_H
#define PLAYGROUND_INSERTIONSORT_H

#include <ISort.h>

class InsertionSort : public ISort {
public:
		void sort(int *arr, int size) override;

		virtual ~InsertionSort() {};
};


#endif //PLAYGROUND_INSERTIONSORT_H
