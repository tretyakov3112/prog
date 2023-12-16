#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;

vector<vector<string>> groupByName(vector<string>& strs) {
  if (strs.size() == 0) {
    vector<vector<string>> ans(0, vector<string>(0, ""));
    return ans;
  }
  vector<vector<string>> ans;
  vector<string> copy_str(strs);
  for (size_t i = 0; i < copy_str.size(); ++i) {
    std::sort(copy_str[i].begin(), copy_str[i].end());
  }
  vector<string> sort_ans;
  sort_ans.push_back(copy_str[0]);
  for (size_t i = 1; i < copy_str.size(); ++i) {
    bool already_was = false;
    for (size_t j = 0; j < sort_ans.size(); ++j) {
      if (copy_str[i] == sort_ans[j]) {
        already_was = true;
      }
    }
    if (!already_was) {
      sort_ans.push_back(copy_str[i]);
    }
  }
  for (size_t i = 0; i < sort_ans.size(); ++i) {
    vector<string> ans_i;
    for (size_t j = 0; j < strs.size(); ++j) {
      if (copy_str[j] == sort_ans[i]) {
        ans_i.push_back(strs[j]);
      }
    }
    ans.push_back(ans_i);
  }
  return ans;
}