#include <iostream>
#include <string>       // std::string
#include <sstream>      // std::stringstream, std::stringbuf



class E {
    friend std::ostream& operator<< (std::ostream& os, const E& e);
};

std::ostream& operator<< (std::ostream& os, const E& e) {
    os << "\n\n";
    std::fflush(stdout);
    return os;
}

bool check(std::string string) {
    for (int i = 0; i < string.length(); ++i)
        if (!isdigit(string[i]))
            return false;
    return true;
}

int main(int argc, const char** argv) { // 1TBS

    std::stringstream ss;
    ss << "hello " << "world";
    std::stringbuf* pbuf = ss.rdbuf();

    char buffer[80];
    pbuf->sgetn(buffer, 3);
    std::cout << buffer << "\n";
    std::cout << buffer << std::endl;

    std::string str1;
    ss >> str1;
    std::cout << str1 << std::endl;


    std::cout << "hello" << E();

    int i;
    std::string s;
    do {
        std::cout << "Enter a number: ";
        std::cin >> s;  // cin >> i
    } while (!check(s)); // !cin.fail()
    i = std::stoi(s);
    std::cout << i << std::endl;


    return 0;
}