#include <iostream>
#include <stdexcept>

class DivistionByZero : public std::runtime_error {
public:
    DivistionByZero(const std::string& what) : std::runtime_error(what) {}
};

template<typename T>
T divide(const T& nominator, const T& denominator) {
    if (denominator == T(0)) {
        throw DivistionByZero("Divistion by Zero");
    }
    return nominator / denominator;
}

class Ex
{
public:
    double x;
    Ex(const double& x_) :x(x_) {}
    ~Ex() {}
};

class Bar
{
private:
    double y;

public:
    Bar() { y = 0; }
    ~Bar() {}
    void set(const double& a)
    {
        if (y + a <= 100)
        {
            y = a;

        }
        else throw Ex(y * a);
    }

};


int main() {
    try {
        std::cout << divide(3, 2) << std::endl;
        std::cout << divide(3.0, 2.0) << std::endl;
        std::cout << divide(1.0, 0.0) << std::endl;
    }
    catch (const DivistionByZero& e) {
        std::cout << e.what() << std::endl;
    }

    Bar b;
    int x{};
    while (std::cin >> x && x != 0) {

        try
        {
            b.set(x);
        }
        catch (Ex& err)
        {
            std::cerr << "Exception: ay " << err.x << std::endl;
        }
    }
    return 0;
}

