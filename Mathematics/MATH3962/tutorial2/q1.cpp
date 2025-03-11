#include <iostream>

int gcdCalc(int a, int b, int &s, int &t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }

    int s1, t1;
    // Recursively calculate gcd
    int gcd = gcdCalc(b, a % b, s1, t1);

    // Back track
    s = t1;
    t = s1 - (a / b) * t1;

    return gcd;
}

int main() {
    int a = 64, b = 15;
    int s, t;
    
    int d = gcdCalc(a, b, s, t);
    
    std::cout << "GCD: " << d << std::endl;
    std::cout << "s: " << s << ", t: " << t << std::endl;
    std::cout << "Verification: " << a << "*" << s << " + " << b << "*" << t << " = " << d << std::endl;

    return 0;
}

// Example for gcd(282, 126, s, t)
// For t = s1 - (a/b) * t1, start at s = 0 and t = s1 - (30 / 6) * t1 = 1 - 5 * 0 = 1;
// Then, s = t1 = 1, t = s1 - (126 / 30) * t1 = 0 - 4 * 1 = -4;