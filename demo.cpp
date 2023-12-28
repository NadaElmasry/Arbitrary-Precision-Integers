#include <iostream>
#include <stdexcept>
#include "bigint.hpp"
using namespace std;

void file_demo(){

}
void static_demo(){

    // two constructors
    BigInt bigint1;
    BigInt bigint2(-67586743224);
    // Uncomment to define incorrect int and throw error
    // try
    // {
    //     BigInt bigint3("+58674TT__def224");
    // }
    // catch (const exception &e)
    // {
    //     cout << "Exception: " << e.what() << endl;
    // }
    BigInt bigint4("-548753");
    cout << "bigint1:" << bigint1 << "  ";
    cout << "bigint2:" << bigint2 << "\n";
    cout << "bigint1 + bigint2 = " << bigint1 + bigint2 << '\n';
    cout << "bigint1 += bigint2 ";
    bigint1 += bigint2;
    bigint2 = bigint4;
    cout << "bigint1:" << bigint1 << "  "
         << "bigint2:" << bigint2 << "  "
         << "bigint4:" << bigint4 << "\n";
    cout << "bigint1 -= bigint2 ";
    bigint1 -= bigint2;
    cout << "bigint1:" << bigint1 << '\n';
    cout << "bigint1 - bigint2 = " << bigint1 - bigint2 << '\n';
    BigInt bigint5(-1);
    cout << "bigint1:" << bigint1 << "  "
         << "bigint5:" << bigint5 << "\n";
    cout << "bigint1 *= bigint5 ";
    bigint1 *= bigint5;
    cout << "bigint1:" << bigint1 << '\n';
    BigInt bigint6 = bigint1 * bigint5;
    cout << "bigint6 = bigint1 * bigint5\n";
    cout << "bigint6:" << bigint6 << '\n';
    -bigint6;
    cout << "bigint6:" << bigint6 << '\n';
    cout << "bigint1:" << bigint1 << "  "
         << "bigint2:" << bigint2 << "  "
         << "bigint4:" << bigint4 << "  "
         << "bigint5:" << bigint5 << "  "
         << "bigint6:" << bigint6 << "\n";
 
    cout << "bigint2 == bigint4 result:" << (bigint2 == bigint4) << '\n';
    bigint2 = 0;
    cout << "bigint1:" << bigint1 << "  "
         << "bigint2:" << bigint2 << "  "
         << "bigint4:" << bigint4 << "  "
         << "bigint5:" << bigint5 << "  "
         << "bigint6:" << bigint6 << "\n";
    cout << "bigint2 != bigint4 result:" << (bigint2 != bigint4) << '\n';
    cout << "bigint1 >= bigint4 result:" << (bigint1 >= bigint4) << '\n';
    cout << "bigint1 <= bigint4 result:" << (bigint1 <= bigint4) << '\n';
    bigint1 = "0";
    cout << "bigint1:" << bigint1 << "  "
         << "bigint2:" << bigint2 << "  "
         << "bigint4:" << bigint4 << "  "
         << "bigint5:" << bigint5 << "  "
         << "bigint6:" << bigint6 << "\n";
    cout << "bigint1 > bigint2 result:" << (bigint1 > bigint2) << '\n';
    cout << "bigint1 < bigint5 result:" << (bigint1 > bigint5) << '\n';
    cout << endl;
}
int main(){

    static_demo();
    return 0;
}