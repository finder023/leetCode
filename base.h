#pragma once

#include <iostream>
#include <climits>


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int emptyVal = INT_MAX;