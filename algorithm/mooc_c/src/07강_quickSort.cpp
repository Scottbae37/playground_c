#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void quickSort(int *ary, int size);

void output(int *ary, int size);

void initArray(int *ary, int n);

int main() {
  int dataList[10000];


  int startTime, endTime;
  int size = sizeof(dataList) / sizeof(dataList[0]);

  srand((unsigned int) time(NULL));

  initArray(dataList, size);

  startTime = clock();
  quickSort(dataList, size);  /* 퀵 정렬 함수 호출 */
  endTime = clock();
  printf("\n\n[ 퀵 정렬  후 출력 ]\n");
  output(dataList, size);
  printf("퀵소트 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));

  getchar();
  startTime = clock();
  quickSort(dataList, size); /* 퀵 정렬 함수 호출 */
  endTime = clock();
  printf("\n\n[ 퀵 정렬  후 출력 ]\n");
  output(dataList, size);
  printf("퀵소트 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));
  getchar();
  return 0;
}

/*----------------------------------------------------------------------
 함수명 및 기능 : quickSort() - 퀵 정렬 함수
 전달인자: ary - 정렬할 데이터 배열의 시작주소
 size - 소트할 데이터의 개수
 리턴값: 없음
 --------------------------------------------------------------------*/
void quickSort(int *ary, int size) {
  int pivot;
  int i = -1, j = size - 1;
  if (size <= 1)
    return; // 구간값이 1이하이면 sort가 완료된 것 이므로 return
  pivot = ary[size - 1];
  // TODO
  while (1) {
    while (ary[++i] < pivot);
    while (j && ary[--j] > pivot);
    if (i < j)
      swap(ary[i], ary[j]);
    else break;
  }
  swap(ary[i], ary[size - 1]);
// 좌측 소구간에 대한 퀵 정렬 재귀 호출
  quickSort(ary, i);
// 우측 소구간에 대한 퀵 정렬 재귀 호출
  quickSort(ary + i + 1, size - i - 1);
}

/*------------------------------------------------------------------------
 함수명 및 기능 : output() - 배열의 모든 원소 출력하기
 전달인자: ary - 정렬할 데이터 배열의 시작주소
 size - 데이터의 개수
 리턴값: 없음
 ------------------------------------------------------------------------*/
void output(int *ary, int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d ", ary[i]);
  }
  printf("\n");
}

/*------------------------------------------------------------------------
 함수명 및 기능 : initArray() - 배열의 원소를 난수로 초기화
 전달인자: ary - 초기화할 데이터 배열의 시작주소
 size - 데이터의 개수
 리턴값: 없음
 ------------------------------------------------------------------------*/
void initArray(int *ary, int n) {
  int i;
  for (i = 0; i < n; ++i)
    ary[i] = rand() % 1000 + 1;
}