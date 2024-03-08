#ifndef TOOLS_H
#define TOOLS_H

#include <Arduino.h>

class Tools {
public:
    // Version for arrays
    template<typename T, size_t N>
    static void forEach(T (&elements)[N], void (*loop)(const T&)) {
        for (size_t iterationCount = 0; iterationCount < N; iterationCount++) {
            loop(elements[iterationCount]);
        }
    }

    // Version for pointers
    template<typename T>
    static void forEach(const T* elements, void (*loop)(const T&)) {
        while (*elements != T()) {  // Use sentinel value or terminate with nullptr
            loop(*elements++);
        }
    }
};

#endif
