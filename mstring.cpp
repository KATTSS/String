#include "mstring.h"

String::String()
{
    data = nullptr;
    length = 0;
    capacity = 0;
}

String::String(const char *ptr)
{
    if (ptr == nullptr) {
        length = 0;
        capacity = 0;
        data = nullptr;
        return;
    }
    length = mystrlen(ptr);
    capacity = length + 1;
    data = std::make_unique<char[]>(capacity);

    for (size_t i = 0; i < length; ++i)
    {
        data[i] = ptr[i];
    }
    data[length] = '\0';
}

String::String(const String &other)
{
    length = other.length;
    capacity = other.capacity;
    data = std::make_unique<char[]>(capacity);

    for (size_t i = 0; i <= length; ++i)
    {
        data[i] = other.data[i];
    }
}

String &String::operator=(const String &other)
{
    if (this == &other)
        return *this;
    
    length = other.length;
    capacity = other.capacity;
    data =std::make_unique<char[]>(capacity);

    for (size_t i = 0; i <= length; ++i)
    {
        data[i] = other.data[i];
    }
   // data[length] = '\0';
    return *this;
}

size_t mystrlen(const char *ptr)
{
    size_t count = 0;
    while (ptr[count] != '\0')
    {
        ++count;
    }
    return count;
}
String& String::operator+=(const String& other) {
    reserve(length + other.length + 1);
    for (size_t i = 0; i <= other.length; ++i) {
        data[length + i] = other.data[i];
    }
    length += other.length;
    return *this;
}

String String::operator+(const String& other) {
    String result = *this;
    result += other;
    return result;
}

void *String::memcpy(void *one, const void *two, size_t num)
{
    for (size_t i = 0; i < num; ++i)
    {
        ((unsigned char *)one)[i] = ((unsigned char *)two)[i];
    }
    return one;
}

void *String::memmove(void *s1, const void *s2, size_t n)
{
    size_t s1len = mystrlen((char *)s1);
    size_t i = 0;
    for (; i < (s1len > n ? n : s1len); ++i)
    {
        ((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
    }
    ((unsigned char *)s1)[i++] = '\0';
    return s1;
}

char *String::strcpy(char *s1, const char *s2)
{
    if (s2 == nullptr)
    {
        return nullptr;
    }
    char *ptr = s1;
    while ((*ptr++ = *s2++) != '\0')
    {
    }
    return s1;
}

char *String::strncpy(char *s1, const char *s2, size_t n)
{
    if (s2 == nullptr || n == 0)
    {
        return s1;
    }
    char *ptr = s1;
    while (n > 0 && (*ptr++ = *s2++) != '\0')
    {
        --n;
    }
    while (n-- > 0)
    {
        *ptr++ = '\0';
    }
    return s1;
}

void String::strcat(char *&one, const char *two)
{
    if (two == nullptr)
        return;
    size_t size1 = mystrlen(one);
    size_t size2 = mystrlen(two);
    size_t cap = size1+size2 +1;
    char *both_in_one = new char[cap];
    for (size_t i = 0; i <= size1; ++i)
    {
        both_in_one[i] = one[i];
    }
    for (size_t i = 0; i < size2; ++i)
    {
        both_in_one[size1 + i] = two[i];
    }
    both_in_one[size1 + size2] = '\0';
    delete[] one;
    one = both_in_one;
}

void String::strncat(char *&one, const char *two, size_t n)
{
    if (two == nullptr)
        return;
    size_t size1 = mystrlen(one);
    size_t size2 = mystrlen(two) > n ? n : mystrlen(two);
    char *both_in_one = new char[size1 + size2 + 1];
    for (size_t i = 0; i <= size1; ++i)
    {
        both_in_one[i] = one[i];
    }
    for (size_t i = 0; i < size2; ++i)
    {
        both_in_one[size1 + i] = two[i];
    }
    both_in_one[size1 + size2] = '\0';
    delete[] one;
    one = both_in_one;
}

void String::reserve(const size_t n) {
    if (n<=capacity) return;
    auto newdata = std::make_unique<char[]>(n);
    for (size_t i = 0; i <= length; ++i) {
        newdata[i] = data[i];
    }
    data.swap(newdata);
    capacity = n;
}

int String::memcmp(const void* s1, const void* s2, size_t n){
    char* ptr1 = (char*)s1;
    char* ptr2 = (char*)s2;
    for (size_t i = 0; i < n; ++i) {
        if (ptr1[i] != ptr2[i]) {
            return (ptr1[i] < ptr2[i]) ? -1 : 1;
        }
    }
    return 0;
}

int String::strcmp(const char* s1, const char* s2){
    int size1 = mystrlen(s1);
    int size2 = mystrlen(s2);
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (s1[i] > s2[j])
            return 1;
        else if (s1[i] < s2[j])
            return -1;
        else
        {
            ++i;
            ++j;
        }
    }
    if (size1 > size2)
        return 1;
    else if (size1 < size2)

        return -1;
        else
        return 0;
}

int String::strcoll(const char *s1, const char *s2) {
    const char *loc = setlocale(LC_COLLATE, NULL);
    if (loc == NULL) {
        return strcmp(s1, s2);
    }

    while (*s1 != '\0' && *s2 != '\0') {
        int c1 = tolower((unsigned char)*s1);
        int c2 = tolower((unsigned char)*s2);

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }

    return (*s1 != '\0') - (*s2 != '\0');
}

int String::strncmp(const char* s1, const char* s2, size_t n){
    int size1 = mystrlen(s1);
    int size2 = mystrlen(s2);
    int i = 0, j = 0;
    while (i < size1 && j < size2 && n>0)
    {
        if (s1[i] > s2[j])
            return 1;
        else if (s1[i] < s2[j])
            return -1;
        else
        {
            ++i;
            ++j;
            --n;
        }
    }
    if (n==0) return 0;

    if (size1 > size2)
        return 1;
    else if (size1 < size2)
        return -1;
    else
        return 0;
}

char* String::strtok(char *str, const char *delim) {
    static char *last = 0;  
    if (str) last = str;   

    while (*last != '\0') {
        const char *d = delim;
        int is_delim = 0;
        while (*d != '\0') {
            if (*last == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (!is_delim) break;
        last++;
    }

    if (*last == '\0') return 0; 

    char *start = last; 
    while (*last != '\0') {
        const char *d = delim;
        int is_delim = 0;
        while (*d != '\0') {
            if (*last == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (is_delim) break;
        last++;
    }

    if (*last == '\0') {
        last = last;  
        return start;
    }

    *last = '\0';      
    last++;           
    return start;
}
void* String::memset(void* s, int c, size_t n) {
    unsigned char* ptr = (unsigned char*)s;
    for (size_t i = 0; i < n; ++i) {
        ptr[i] = (unsigned char)c;
    }
    return s;
}

void String::print() {
    for (size_t i = 0; i<length; ++i) {
        std:: cout << data[i];
    }
    std::cout << '\n';
}