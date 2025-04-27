#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <iostream>
#include <memory>
#include "../../LR4/Task4/OwnIterator.h"

size_t mystrlen(const char *ptr);

class String
{
public:
    typedef OwnIterator<char> iterator;

    String();
    String(const char *ptr);
    String(const String &other);
    ~String() = default;

    String &operator=(const String &other);
    String& operator+=(const String& other);
    String operator+(const String &other);

    void *memcpy(void *one, const void *two, size_t num);
    void *memmove(void *s1, const void *s2, size_t n);

    char *strcpy(char *s1, const char *s2);
    char *strncpy(char *s1, const char *s2, size_t n);

    void strcat(char *&one, const char *two);
    void strncat(char *&one, const char *two, size_t n);

    int memcmp(const void* s1, const void* s2, size_t n);
    int strcmp(const char* s1, const char* s2);
    int strcoll(const char *s1, const char *s2);
    int strncmp(const char* s1, const char* s2, size_t n);

    char* strtok(char *str, const char *delim);

    void* memset(void* s, int c, size_t n);

    void print();

    std::unique_ptr<char[]> data;

private:
    // std::unique_ptr<char[]> data;
    size_t length;
    size_t capacity;

    void reserve(const size_t n);
    
 };

#endif // STRING_H