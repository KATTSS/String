# Custom String Class Implementation in C++

A custom C++ string class that provides functionality similar to standard C-string manipulation functions with modern C++ memory management using `std::unique_ptr`.

## Features
- **Memory Management**: Uses `std::unique_ptr<char[]>` for automatic memory management
- **Standard C-String Functions**: Implements common C string manipulation functions as class methods
- **Iterator Support**: Includes `OwnIterator<char>` for iteration capabilities
- **Operator Overloading**: Supports `+`, `+=`, and assignment operators
- **Safe Operations**: Includes bounds checking and null pointer handling
- **Locale Support**: `strcoll()` function for locale-aware string comparison

## Technologies
C++
