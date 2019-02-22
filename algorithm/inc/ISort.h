#ifndef PLAYGROUND_ISORT_H
#define PLAYGROUND_ISORT_H

class ISort {
public:
		virtual void sort(int *arr, int size) = 0;

		virtual ~ISort() {};
};

#endif //PLAYGROUND_ISORT_H
