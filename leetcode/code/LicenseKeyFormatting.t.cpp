#include "gtest/gtest.h"
#include "LicenseKeyFormatting.h"

TEST(LicenseKeyFormatting, LicenseKeyFormatting)
{
    LicenseKeyFormatting sol;
    EXPECT_EQ("24A0-R74K", sol.licenseKeyFormatting("2-4A0r7-4k", 4));
    EXPECT_EQ("24-A0R-74K", sol.licenseKeyFormatting("2-4A0r7-4k", 3));
}

TEST(LicenseKeyFormatting, ExceptionCase)

{
    LicenseKeyFormatting sol;
    EXPECT_EQ("", sol.licenseKeyFormatting("---", 3));
}
