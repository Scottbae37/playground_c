//
// Created by scottbae37 on 11/02/2019.
//

#include <iostream>

using namespace std;

#define N 6

int result[N];

void merge_sort(int array[], int left, int right); //분할 함수
void merge(int num[], int left, int mid, int right); //병합 함수

void merge_sort(int *arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

//void merge(int *num, int left, int mid, int right) {
//  // 작은 순서대로 배열에 삽입
//
//  // 남은 데이터도 삽입
//
//  // 정렬된 배열에 삽
//}
void merge(int array[], int left, int mid, int right) {
  int i, j, k, m;
  i = left;
  j = mid + 1;
  k = left; //결과 배열의 인덱스
  int tempArray[N]; //left부터 mid 까지의 블록과 mid+1부터 right까지의 블록을 서로 비교하는 부분
  while (i <= mid && j <= right) {
    if (array[i] < array[j]) { //left index 값이 right index 값보다 작으면 left index 값을 결과 result 에 복사
      tempArray[k] = array[i];
      i++;
    } else { //아니라면 right index 값을 결과 result에 복사
      tempArray[k] = array[j];
      j++;
    }
    k++;
  } // left 블록의 값은 다 처리되었는데 right 블록의 index가 아직 남아있을 경우
  // right index를 순차적으로 결과 result에 복사
  if (i > mid) {
    for (m = j; m <= right; m++) {
      tempArray[k] = array[m];
      k++;
    }
  } else { // left 블록의 index가 아직 남아있을 경우 left index를 순차적으로 결과 result에 복사
    for (m = i; m <= mid; m++) {
      tempArray[k] = array[m];
      k++;
    }
  }
  for (m = left; m <= right; m++) { array[m] = tempArray[m]; }
}


int main(void) {
  int array[N] = {10, 3, 8, 0, 2, 1};
  merge_sort(array, 0, N - 1);
  for (int i = 0; i < N; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}