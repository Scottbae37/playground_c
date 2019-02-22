#ifndef PLAYGROUND_BUBBLESORT_H
#define PLAYGROUND_BUBBLESORT_H

#include <ISort.h>

class BubbleSort : public ISort {
public:
		virtual void sort(int *arr, int size) override;

		virtual ~BubbleSort() {};
};


#endif //PLAYGROUND_BUBBLESORT_H
