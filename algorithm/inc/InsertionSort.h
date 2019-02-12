#ifndef PLAYGROUND_INSERTIONSORT_H
#define PLAYGROUND_INSERTIONSORT_H


class InsertionSort {
private:
    void swap(int *arr, int i, int j) const;
public:
    void sort(int *arr, int size);
    void sort3(int *arr, int size);
};


#endif //PLAYGROUND_INSERTIONSORT_H
