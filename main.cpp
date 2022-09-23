#include <xbyak/xbyak.h>

struct Code : Xbyak::CodeGenerator {
    Code(int x)
    {
        mov(eax, x);
        ret();
    }
};

int main() {

    Code c(5);
    int (*f)() = c.getCode<int (*)()>();
    std::cout << "ret = " << f() << std::endl; // ret = 5
}