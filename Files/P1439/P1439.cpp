#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

int main() {
    long double a = 1e17L - 156L;  // 使用L后缀确保long double常量
    long double b = 1e17L - 156L;
    long double product = a * b;

    // 方法1：使用printf保证输出精度
    printf("a * b (long double) = %.35Lf\n", product);
    
    // 方法2：十六进制输出查看实际存储
    unsigned char* bytes = (unsigned char*)&product;
    std::cout << "Bytes: ";
    for(size_t i = 0; i < sizeof(product); ++i)
        printf("%02x ", bytes[i]);
    std::cout << "\n";

    return 0;
}