#!/bin/bash

# this script is used to generate the template for coding practice

fileName=$1

# genearte .h file
cat << EOF >> "$fileName".h
/*
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

private:

};
EOF

cat << EOF >> "$fileName".t.cpp
#include "gtest/gtest.h"
#include "${fileName}.h"

TEST($fileName, ) {
    Solution sol;

}
EOF
