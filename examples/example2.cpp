#include "print.h"
#include <string>

int main() {
    std::string message = "Hello from example2!";
    print(message);
    
    print("Testing multiple lines");
    print("End of example2");
    
    return 0;
}
