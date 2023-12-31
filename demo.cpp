#include <iostream>
#include <stdexcept>
#include "bigint.hpp"
using namespace std;

void file_demo() {
}
void static_demo() {

     BigInt bigint1;
     BigInt bigint2(5743885);
     BigInt bigint3(-1465997);
     BigInt bigint4("-548753");
     BigInt bigint5("+15432");

     cout << "bigint1 - defined using empty constructor: " << bigint1 << endl;
     cout << "bigint2 - defined using int constructor: " << bigint2 << endl;
     cout << "bigint3 - defined using int constructor: " << bigint3 << endl;
     cout << "bigint4 - defined using string constructor: " << bigint4 << endl;
     cout << "bigint5 - defined using string constructor: " << bigint5 << endl;

     BigInt bigint6 = bigint5 + bigint2;
     cout << "bigint6 = bigint5 + bigint2 , bigint6 = " << bigint6 << endl;
     cout << "-bigint6 = " << -bigint6 << endl;

     BigInt bigint7;
     BigInt bigint8(0);
     bigint7 = 66587;
     bigint8 = "8847321";
     cout << "bigint7 - defined by the = operator, bigint7 = " << bigint7 << endl;
     cout << "bigint8 - defined by the = operator, bigint8 = " << bigint8 << endl;

     bigint1 -= bigint6;
     bigint4 = BigInt(-55400) - BigInt(87659);
     bigint8 = BigInt(-55400) * BigInt(87659);
     cout<< "bigint1-=bigint6 : " << bigint1 << endl;
     cout << "bigint4 = BigInt(-55400) - BigInt(87659) , bigint4 = " << bigint4 << endl;
     cout << "bigint5 += bigint7 : " << (bigint5 += bigint7) << endl;
     cout << "bigint7 *= bigint2 : " << (bigint7 *= bigint2) << endl;
     cout << "bigint8 = BigInt(-55400) * BigInt(87659), bigint8 =  " << bigint8 << endl;
     cout << "bigint1 -= bigint6 : " << bigint1 << endl;
     cout << "bigint4 = bigint1 - bigint5, bigint4 = " << bigint4 << endl;

     cout << "bigint2 != bigint4 : " << (bigint2 != bigint4) << endl;
     cout << "bigint2 == bigint4 : " << (bigint2 == bigint4) << endl;
     cout << "bigint1 == bigint1 : " << (bigint1 == bigint1) << endl;
     cout << "bigint1 > bigint8 : " << (bigint1 > bigint8) << endl;
     cout << "bigint1 >= bigint8 : " << (bigint1 >= bigint8) << endl;
     cout << "bigint1 < bigint8 : " << (bigint1 < bigint8) << endl;
     cout << "bigint1 <= bigint8 : " << (bigint1 <= bigint8) << endl;


     // Uncomment to define incorrect bigint and throw error
     //     try {
     //         BigInt bigint6("+58674TT__def224");
     //     }
     //     catch (const exception &e) {
     //         cout << "Exception: " << e.what() << endl;
     //     }

     //     try {
     //          BigInt bigint9("+");
     //     }
     //     catch (const exception &e) {
     //          cout << "Exception: " << e.what() << endl;
     //     }


}

int main() {
     static_demo();
     return 0;
}