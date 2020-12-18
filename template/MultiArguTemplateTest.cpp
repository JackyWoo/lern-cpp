//
// Created by wujianchao5 on 2020/12/23.
//

#include <>
#include <iostream>

/**
 * 实现 printf 函数功能
 */
template<typename T, typename... R>
void printf(const char *format, T value, R... args) {
    // recursive variadic function
    for (; *format != '\0'; format++) {
        if (*format == '%') {
            std::cout << value;
            printf(format + 1, args...);// recursive call
            return;
        }
        std::cout << *format;
    }
}

void show(int a, ...) {
}

int main() {
    printf("% world% %\n", "Hello", '!', 123);
    return 0;
}