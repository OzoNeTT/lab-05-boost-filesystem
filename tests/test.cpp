#include <gtest/gtest.h>
#include "broker.hpp"

TEST(test, simple) {
    string path_to_ftp = "../";
    fileFind(path_to_ftp, path_to_ftp.length() + 1);
    FileGet();
    EXPECT_EQ(brokers.size(), 3);
}