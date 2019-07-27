#ifndef LINKED_LIST_HELPER_H
#define LINKED_LIST_HELPER_H

#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void trimLeftTrailingSpaces(std::string &input) {
  input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(std::string &input) {
  input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
  std::vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  std::stringstream ss;
  ss.str(input);
  std::string item;
  char delim = ',';
  while (std::getline(ss, item, delim)) {
    output.push_back(std::stoi(item));
  }
  return output;
}

ListNode *stringToListNode(std::string input) {
  // Generate list from the input
  std::vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

#endif // LINKED_LIST_HELPER_H