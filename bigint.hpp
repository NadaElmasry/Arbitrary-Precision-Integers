#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

// Class Headers
class BigInt
{
public:
    /**
     * @brief Construct a new Big Int object, initializes it to 0
     *
     */
    BigInt();
    /**
     * @brief Construct a new Big Int object, initializes it to the given 64-bit integer
     *
     * @param number - 64-bit integer
     */
    BigInt(const int64_t number);  
    /**
     * @brief Construct a new Big Int object from a string
     *
     * @param number  - pointer to a string
     */
    BigInt(const string &number);
    /**
     * @brief Construct a new Big Int object from another BigInt object
     *
     * @param bigint - another BigInt number 
     */
    BigInt(const BigInt &bigint);
    /**
     * @brief returns the sign of BigInt
     *
     * @return true if the number is negative
     * @return false if the number is positive
     */
    bool signNegative() const;
    /**
     * @brief Get the Size of the bigint vector , gets the number of digits in a bigint.
     *
     * @return size_t - the size of the vector  aka the number of digits.
     */
    size_t getSize() const;
    /**
     * @brief Get the digit at position i in the array
     *
     * @param i - index of element wanted 
     * @return uint32_t number - the element at position i in the bigint vector.
     */
    uint32_t getElement(const size_t) const;
    /**
     * @brief Adds the absolute values of two BigInts.
     *
     * @param bigint - BigInt number to be added to the current one.
     *
     * @return BigInt - the absolute number resulted from the addition operation.
     */
    BigInt AbsoluteAddition(const BigInt &bigint);
    /**
     * @brief Subtracts two absolute values, subtracts the smaller element from the bigger one. Works only if the LHS > RHS
     * 
     * @param bigint - number to be subtracted from the LHS.
     * @return BigInt - the result of the subtraction operation.
     */

    BigInt AbsoluteSubtraction(const BigInt &bigint);
    /**
     * @brief Compares two absolute values. Returns true if LHS > RHS
     * 
     * @param bigint - value to be compared with LHS
     * @return true - if LHS > RHS
     * @return false - if LHS < RHS
     */

    bool compareAbsoluteValues(const BigInt &bigint);
   /**
    * @brief overload negation operation. Negates bigint number.
    * 
    * @return BigInt - the negated BigInt
    */

    BigInt &operator-();

    /**
     * @brief overload += operator. Adds the input BigInt to the BigInt on the LHS. Adds in place and returns the BigInt
     * 
     * @return BigInt - the result of the + operation.
     */
    BigInt &operator+=(const BigInt &bigint);
    /**
     * @brief overload -= operator. Subtracts the input BigInt from the BigInt on the LHS. Subtracts in place and returns the BigInt
     *
     * @return BigInt - the result of the - operation.
     */

    BigInt &operator-=(const BigInt &bigint);
    /**
     * @brief overload *= operator. Multiplies the input BigInt by the BigInt on the LHS. Multiplies in place and returns the BigInt
     *
     * @return BigInt - the result of the * operation.
     */

    BigInt &operator*=(const BigInt &bigint);
    /**
     * @brief overloads the assignment operator to assign the value of BigInt to the value of the input BigInt. Modifies the BigInt in place and returns the new instance too.
     *
     * @param bigint - BigInt number to assign to LHS BigInt.
     * @return BigInt - the modified BigInt
     */

    BigInt &operator=(const BigInt &bigint);
    /**
     * @brief overloads the assignment operator to assign the value of BigInt to the value of the input number. Modifies the BigInt in place and returns the new instance too.
     *
     * @param number - 64-bit integer to assign to LHS BigInt.
     * @return BigInt - the modified BigInt
     */
    BigInt &operator=(const int64_t number);
    /**
     * @brief overloads the assignment operator to assign the value of BigInt to the value of the input string. Modifies the BigInt in place and returns the new instance too.
     *
     * @param number - string of integer to assign to LHS BigInt.
     * @return BigInt - the modified BigInt
     */

    BigInt &operator=(const string &number);

    private:
        vector<uint32_t> bigint; /*** @brief - vector to store the digits of the bigint as unsigned 32-bit integers**/
        bool sign_negative = false; /*** @brief - boolean to store if the bigint sign is negative or positive. **/
};
/**
 * @brief overloads the output stream to enable the printing of the vector containing the bigint digits. The output is formatted to appear as one integer.
 *
 * @param out - output stream from std library to be used for printing.
 * @param bigint - the BigInt number to print.
 * @return ostream& - the output stream with the required format for printing BigInt.
 */
ostream &operator<<(ostream &out, const BigInt &bigint);

/**
 * @brief - overload the == operator. Checks if the two BigInts are equal by comparing the size and signs of the BigInts and if equal iterates through all the digits and 
 * compares them one by one.
 *
 * @param lhs - BigInt number
 * @param rhs - BigInt number
 * @return true - if LHS == RHS
 * @return false - if LHS != RHS
 */

bool operator==(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief - overload the != operator. negates the result of the == operator.
 *
 * @param lhs - BigInt number
 * @param rhs - BigInt number
 * @return true - if LHS != RHS
 * @return false - if LHS == RHS
 */
bool operator!=(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief - overload the > operator. Checks if the LHS BigInt is greater than the RHS BigInt by comparing the size and signs of the BigInts and if equal iterates through all the digits and
 * compares them one by one.
 *
 * @param lhs - BigInt number
 * @param rhs - BigInt number
 * @return true - if LHS > RHS
 * @return false - if LHS < RHS
 */
bool operator>(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief - overload the < operator. uses the negation of the > operator.
 * @param lhs - BigInt number
 * @param rhs - BigInt number
 * @return true - if LHS < RHS
 * @return false - if LHS > RHS
 */
bool operator<(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief overloads the >= operator. performs an OR operation that uses the results of the == and > operators
 *
 * @param lhs - BigInt number
 * @param rhs - BigInt number
 * @return true - if LHS > RHS OR LHS == RHS
 * @return false - f LHS < RHS OR LHS != RHS
 */
bool operator>=(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief overloads the <= operator. performs an OR operation that uses the results of the == and < operators
 *
 * @param lhs - BigInt number
 * @param rhs - BigInt number
 * @return true - if LHS < RHS OR LHS == RHS
 * @return false - f LHS > RHS OR LHS != RHS
 */
bool operator<=(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief overloads the + operator. Adds two BigInts and changes the sign accordingly.
 * 
 * @return BigInt - the result of the addition operation
 */
BigInt operator+(BigInt, const BigInt &);
/**
 * @brief overloads the - operator. Subtracts two BigInts and changes the sign accordingly.
 *
 * @return BigInt - the result of the subtraction operation
 */
BigInt operator-(BigInt, const BigInt &);
/**
 * @brief overloads the * operator. Multiplies two BigInts and changes the sign accordingly.
 *
 * @return BigInt - the result of the multiplication operation.
 */
BigInt operator*(BigInt, const BigInt &);




ostream &operator<<(ostream &out, const BigInt &bigint)
{
    // check if the number is negative and print the sign 
    if (bigint.signNegative() && (!(bigint.getSize() == 1 && bigint.getElement(0) == 0)))
    {
        out << '-';
    }
    // iterate over the BigInt vector and print the digits
    for (size_t i = bigint.getSize() - 1; i > 0; i--)
    {
        out << bigint.getElement(i);
    }
    out << bigint.getElement(0);

    return out;
}


BigInt::BigInt()
{
    // initialize a zero vector from the empty constructor
    bigint.push_back(0);
}

BigInt::BigInt(int64_t number)
{
    // assign the right sign to the BigInt
    sign_negative = number < 0;
    // use the absolute value of the integer to build the BigInt vector
    int64_t unsigned_number = abs(number);
    if (unsigned_number == 0)
    {
        bigint.push_back(0);
    }
    else
    {
        // push the digits of the input integer to the vector as 32-bit integers in reverse order.
        while (unsigned_number > 0)
        {
            bigint.push_back(static_cast<uint32_t>(unsigned_number % 10));
            unsigned_number /= 10;
        }
    }
    
}

BigInt::BigInt(const string &number)
{
    // assign the right sign to the BigInt
    sign_negative = (number[0] == '-');
    // checks if the user entered the sign of the integer
    bool sign_entered = (sign_negative || number[0] == '+');
    size_t start = 0;
    // check to make sure the user entered the integer not only the sign 
    if (number.size() == 1 && sign_entered)
    {
        throw invalid_argument("Invalid integer. The sign of the number only was entered. No integer was entered");
    }
    // if the user entered the sign of the integer begin inserting into the vector from index 1 as index 0 is taken by the sign.
    if (sign_entered)
    {
        start = 1;
    }
    // push the digits of the input integer to the vector as 32-bit integers in reverse order.
    for (size_t i = number.size() - 1; i >= start; i--)
    {
        // checks if the character at index i is a digit from 0-9.
        if (!((number[i] - '0' <= 9) && (number[i] - '0' >= 0)))
        {
            throw invalid_argument("Invalid Integer. A non-digit value was entered. Please enter only digits from 0-9");
        }
        bigint.push_back(static_cast<uint32_t>(number[i] - '0'));
        if (i == 0)
        {
            break;
        }
    }
}

// build a BigInt instance from an existing BigInt instance
BigInt::BigInt(const BigInt &number) : bigint(number.bigint), sign_negative(number.sign_negative) {}

BigInt &BigInt::operator=(const BigInt &number)
{
    sign_negative = number.signNegative();
    bigint = number.bigint;

    return *this;
}

BigInt &BigInt::operator=(const int64_t number)
{
    BigInt temp(number);
    sign_negative = temp.signNegative();
    bigint = temp.bigint;

    return *this;
}

BigInt &BigInt::operator=(const string &number)
{
    BigInt temp(number);
    sign_negative = temp.signNegative();
    bigint = temp.bigint;
    return *this;
}

size_t BigInt::getSize() const
{
    // returns the size/ number of elements of the bigint vector
    return bigint.size();
}

bool BigInt::signNegative() const
{
    // returns True if number is negative and false if positive
    return sign_negative;
}

uint32_t BigInt::getElement(const size_t i) const
{
    // returns the element of the vector bigint at index i.
    return bigint.at(i);
}

BigInt &BigInt::operator-()
{
    if (!(bigint.size() == 1 && bigint[0] == 0))
    {
        sign_negative = !sign_negative;
    }

    return *this;
}

bool operator==(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.signNegative() != rhs.signNegative())
    {
        return false;
    }
    if (lhs.getSize() != rhs.getSize())
    {
        return false;
    }
    for (size_t i = lhs.getSize() - 1; i >= 0; i--)
    {
        if (lhs.getElement(i) != rhs.getElement(i))
        {
            return false;
        }
        if (i == 0)
        {
            break;
        }
    }
    return true;
}

bool operator!=(const BigInt &lhs, const BigInt &rhs)
{
    return !(lhs == rhs);
}

bool operator>(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.signNegative() != rhs.signNegative())
    {
        return (!lhs.signNegative());
    }
    if (lhs.getSize() != rhs.getSize())
    {
        return (lhs.getSize() > rhs.getSize());
    }
    for (size_t i = lhs.getSize() - 1; i >= 0; i--)
    {
        if (lhs.getElement(i) != rhs.getElement(i))
        {
            return (!lhs.signNegative() ^ (lhs.getElement(i) > rhs.getElement(i)));
        }
        if (i == 0)
        {
            break;
        }
    }
}

bool operator<(const BigInt &lhs, const BigInt &rhs)
{
    return (rhs > lhs);
}

bool operator>=(const BigInt &lhs, const BigInt &rhs)
{
    return ((lhs == rhs) || (lhs > rhs));
}

bool operator<=(const BigInt &lhs, const BigInt &rhs)
{
    return ((lhs == rhs) || (lhs < rhs));
}

BigInt &BigInt::operator+=(const BigInt &rhs)
{
    // checks if the two BigInts have the same sign. If True perform addition
    if (sign_negative == rhs.sign_negative)
    {
        *this = AbsoluteAddition(rhs);
    }
    // if LHS BigInt is greater than RHS BigInt and they are different signs, subtract RHS from LHS
    else if (compareAbsoluteValues(rhs))
    {
        *this = AbsoluteSubtraction(rhs);
    }
    // if LHS BigInt is smaller than RHS BigInt and they are different signs, subtract LHS from RHS
    else
    {
        BigInt result(rhs);
        *this = result.AbsoluteSubtraction(*this);
        sign_negative = result.sign_negative;
    }

    return *this;
}

BigInt &BigInt::operator-=(const BigInt &rhs)
{
    // checks if the BigInts have opposite sign. If so then perform addition on the absolute values and keep the current sign as it is.
    if (sign_negative != rhs.sign_negative)
    {
        *this = AbsoluteAddition(rhs);
    }
    // if the LHS is greater than the RHS and they have the same sign, subtract RHS from LHS
    else if (compareAbsoluteValues(rhs))
    {
        *this = AbsoluteSubtraction(rhs);
    }
    // if the LHS is smaller than the RHS and they have the same sign, subtract LHS from RHS
    else
    {
        BigInt result(rhs);
        *this = result.AbsoluteSubtraction(*this);
        sign_negative = !sign_negative;
    }

    return *this;
}

BigInt &BigInt::operator*=(const BigInt &rhs)
{
    // Initialize result with size bigger than the two BigInts combined and initialize elements with zero
    vector<uint32_t> result(bigint.size() + rhs.getSize()+1,0);
    // Assign the output sign (+ if LHS and RHS have same signs and - otherwise)
    sign_negative = (!(sign_negative == rhs.sign_negative));

    // Perform multiplication digit by digit
    for (size_t i = 0; i < bigint.size(); i++)
    {
        uint32_t carry = 0;
        uint64_t current;
        for (size_t j = 0; j < rhs.getSize() || carry; j++)
        {
            if (j == result.size()){
                result.push_back(0);
                }

            current = static_cast<uint64_t> (result[i + j] + (bigint[i]) * (j < rhs.getSize() ? rhs.getElement(j) : 0) + carry);
            result[i + j] = static_cast<uint32_t>(current % 10);
            carry = static_cast<uint32_t>(current / 10);
        }
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }

    bigint = result;
    return *this;
}

BigInt operator+(BigInt lhs, const BigInt &rhs)
{
    lhs += rhs;
    return lhs;
}

BigInt operator-(BigInt lhs, const BigInt &rhs)
{
    lhs -= rhs;
    return lhs;
}

BigInt operator*(BigInt lhs, const BigInt &rhs)
{
    lhs *= rhs;
    return lhs;
}

BigInt BigInt::AbsoluteAddition(const BigInt &rhs)
{
    size_t maxLen = max(bigint.size(), rhs.bigint.size());

    // Ensure enough space in the result vector
    bigint.resize(maxLen + 1, 0);

    uint32_t carry = 0;
    for (size_t i = 0; i < maxLen || carry; ++i)
    {
        uint32_t sum = bigint[i] + carry;
        if (i < rhs.bigint.size())
            sum += rhs.bigint[i];

        bigint[i] = sum % 10;
        carry = sum / 10;
    }

    // Remove leading zeros
    while (bigint.size() > 1 && bigint.back() == 0)
    {
        bigint.pop_back();
    }

    return *this;
}

BigInt BigInt::AbsoluteSubtraction(const BigInt &rhs)
{
    // if the user entered RHS BigInt > LHS BigInt then throw an error as the logic of the function assumes LHS > RHS
    if (!compareAbsoluteValues(rhs)){
        throw logic_error("BigInt passed as argument (right hand side - RHS) is larger than the BigInt calling the function (left hand side - LHS). \\
        Absolute Subtraction only works when LHS > RHS.");
    }

    size_t maxLen = max(bigint.size(), rhs.getSize());

    // Ensure enough space in the result vector
    bigint.resize(maxLen + 1, 0);
    for (size_t i = 0; i < bigint.size(); i++)
    {
        // store the subtraction result 
        int32_t difference = int32_t(bigint[i]);
        if (i < rhs.getSize())
        {
            difference -= int32_t(rhs.getElement(i));
        }
        // if the digit needs to borrow from the next digit. 
        if (difference < 0)
        {
            difference += 10;
            bigint[i + 1] -= 1;
        }

        bigint[i] = static_cast<uint32_t>(difference);
    }

    // Remove leading zeros
    while (bigint.size() > 1 && bigint.back() == 0)
    {
        bigint.pop_back();
    }

    return *this;
}

// checks if the LHS BigInt is greater than the RHS BigInt. Useful in Subtraction and Addition operations.
bool BigInt::compareAbsoluteValues(const BigInt &rhs)
{
    if (bigint.size() != rhs.getSize())
    {
        return (bigint.size() > rhs.getSize());
    }
    for (size_t i = bigint.size() - 1; i >= 0; i--)
    {
        if (bigint[i] != rhs.getElement(i))
        {
            return (bigint[i] > rhs.getElement(i));
        }
        if (i == 0)
        {
            break;
        }
    }
    return true;
}


