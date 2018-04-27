#include "gtest/gtest.h"
#include "SimplifyPath.h"

TEST(SimplifyPath, SimplifyPath)
{
    SimplifyPath sol;
    string path("/home/");
    EXPECT_EQ("/home", sol.simplifyPath(path));
    path = "/a/./b/../../c/";
    EXPECT_EQ("/c", sol.simplifyPath(path));
    path = "////a/./b/../../c/";
    EXPECT_EQ("/c", sol.simplifyPath(path));
    path = "/";
    EXPECT_EQ("/", sol.simplifyPath(path));
    path = "/...";
    EXPECT_EQ("/...", sol.simplifyPath(path));
    path = "/a/b///.//../c";
    EXPECT_EQ("/a/c", sol.simplifyPath(path));
}
