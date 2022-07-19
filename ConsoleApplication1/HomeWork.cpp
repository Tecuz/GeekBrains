#include <iostream>

template<typename T>
class Pair {
    T a;
    T b;
public:
    Pair(T k, T v) : a(k), b(v) { }
    ~Pair() {}
    T first() const;
    T second() const { return b; }
    void setFirst(T k) { a = k; }
};
template<typename T>
T Pair<T>::first() const { return a; }

template<typename First, typename Second>
class DPair {
protected:
    First a;
    Second b;
public:
    DPair(First k, Second v) : a(k), b(v) { }
    ~DPair() {}
    virtual First first() const { return a; }
    Second second() const;
};
template<typename First, typename Second>
Second DPair<First, Second>::second() const { return b; }

template<typename Value>
class SPair : public DPair<std::string, Value> {
    std::string a;
public:
    SPair(std::string k, Value v) : DPair<std::string, Value>(k, v), a(k) { }
    ~SPair() {}
    std::string first() const;
};

template<typename Value>
std::string SPair<Value>::first() const {
    std::cout << a;
    return "";
}

int main(int argc, const char** argv) { // 1TBS
    Pair<int> p1(6, 9);
    std::cout << "Pair:  " << p1.first() << ", " << p1.second() << '\n';

    const Pair<double> p2(3.4, 7.8);
    std::cout << "Pair:  " << p2.first() << ", " << p2.second() << '\n';

    DPair<int, double> p3(6, 7.8);
    std::cout << "DPair: " << p3.first() << ", " << p3.second() << '\n';

    const DPair<double, int> p4(3.4, 5);
    std::cout << "DPair: " << p4.first() << ", " << p4.second() << '\n';

    SPair<double> p5("cat", 7.8);
    std::cout << "SPair: " << p5.first() << ", " << p5.second() << '\n';

    const SPair<int> p6("dog", 5);
    std::cout << "SPair: " << p6.first() << ", " << p6.second() << '\n';

    return 0;
}