#include <iostream>

class Cvec {
    public:
        int x, y;
        Cvec () {}
        Cvec(int a, int b) : x(a), y(b) {}
        Cvec operator+ (const Cvec& p) {
            Cvec temp;
            temp.x = x + p.x;
            temp.y = y + p.y;
            return temp;     
        }

};


int
main(void)
{
    Cvec a(3, 1);
    Cvec b(1, 2);
    Cvec c = a + b;
    std::cout << c.x <<std::endl;
    std::cout << c.y <<std::endl;
    return 0;
}
