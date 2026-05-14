#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>
#include <fstream>

void print(const std::string& text);
void print(const std::string& text, std::ostream& out);
void print(const std::string& text, const std::string& filename);

#endif // PRINT_H
