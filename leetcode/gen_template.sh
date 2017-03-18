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
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class $fileName {
public:

private:

};
EOF

cat << EOF >> "$fileName".t.cpp
#include "gtest/gtest.h"
#include "${fileName}.h"

TEST($fileName, $fileName) {
    $fileName sol;

}
EOF
