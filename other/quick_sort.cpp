#include <algorithm>
#include <iostream>
#include <vector>

// 這才是正統快速排序
// 他媽的網路一堆快速排序都在亂寫幹她老師
template <typename T>
void quick_sort_recursive(std::vector<T> &arr, int start, int end) {
  if (start >= end)
    return;

  T mid = arr[end];
  int left = start, right = end - 1;

  while (left < right) {
    while (arr[left] < mid && left < right)
      left++;
    while (arr[right] >= mid && left < right)
      right--;

    std::swap(arr[left], arr[right]);
  }

  // 最後停止的位置是不是大於等於 mid,是的話要把 mid 移動到正確位置,才會符合左半邊都小於mid,右半邊都大於mid.
  if (arr[left] >= arr[end]) // (arr[end] = mid)
    std::swap(arr[left], arr[end]);
  else
    left++; // 停止位置沒有大於 mid, left++ 分出左半右半

  quick_sort_recursive(arr, start, left - 1);
  quick_sort_recursive(arr, left + 1, end);
}

template <typename T>
void quick_sort(std::vector<T> &arr) {
  quick_sort_recursive(arr, 0, arr.size() - 1);
}

int main() {
  std::vector<int> arr = {4, 1, 4, 55, 3, 21, 43, 56, 7, 2, 2, 2, 20, 0, 4, 6, 7, 1, 10};
  quick_sort(arr);

  for (auto n : arr)
    std::cout << n << " ";

  std::cout << std::endl;

  return 0;
}