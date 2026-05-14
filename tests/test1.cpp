#include <fstream>
#include <gtest/gtest.h>
#include <print.h>

TEST(Print, InFileStream) {
    const std::string filepath = "test.txt";
    std::ofstream out{filepath};
    print("Hello", out);  
    
    std::ifstream in{filepath};
    std::string content;
    std::getline(in, content);
    
    EXPECT_EQ(content, "Hello");
}
