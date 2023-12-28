#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
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
     * @brief Construct a new Big Int object
     *
     * @param number
     */
    BigInt(const string &number);
    /**
     * @brief Construct a new Big Int object
     *
     */
    BigInt(const BigInt &);
    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool signNegative() const;
    /**
     * @brief Get the Size object
     *
     * @return size_t
     */
    size_t getSize() const;
    /**
     * @brief Get the Element object
     *
     * @param i
     * @return uint8_t
     */
    uint8_t getElement(const size_t i) const;
    /**
     * @brief
     *
     * @return BigInt
     */
    BigInt AbsoluteAddition(const BigInt &);
    /**
     * @brief
     *
     * @return BigInt
     */

    BigInt AbsoluteSubtraction(const BigInt &);
    /**
     * @brief
     *
     * @return true
     * @return false
     */

    bool compareAbsoluteValues(const BigInt &);
    /**
     * @brief
     *
     */

    void copyElements(const BigInt &);
    /**
     * @brief
     *
     * @return BigInt&
     */

    BigInt &operator-();
    /**
     * @brief
     *
     * @return BigInt&
     */

    BigInt &operator+=(const BigInt &);
    /**
     * @brief
     *
     * @return BigInt&
     */

    BigInt &operator-=(const BigInt &);
    /**
     * @brief
     *
     * @return BigInt&
     */

    BigInt &operator*=(const BigInt &);
    /**
     * @brief
     *
     * @param bigint
     * @return BigInt&
     */

    BigInt &operator=(const BigInt &bigint);
    /**
     * @brief
     *
     * @param number
     * @return BigInt&
     */

    BigInt &operator=(const int64_t number);
    /**
     * @brief
     *
     * @param number
     * @return BigInt&
     */

    BigInt &operator=(const string &number);

private:
    vector<uint8_t> bigint;
    bool sign_negative = false;
};
/**
 * @brief
 *
 * @param out
 * @param bigint
 * @return ostream&
 */
ostream &operator<<(ostream &out, const BigInt &bigint);

/**
 * @brief
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */

bool operator==(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
bool operator!=(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
bool operator>(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
bool operator<(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
bool operator>=(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
bool operator<=(const BigInt &lhs, const BigInt &rhs);
/**
 * @brief
 *
 * @return BigInt
 */

BigInt operator+(BigInt, const BigInt &);
/**
 * @brief
 *
 * @return BigInt
 */
BigInt operator-(BigInt, const BigInt &);
/**
 * @brief
 *
 * @return BigInt
 */
BigInt operator*(BigInt , const BigInt &);

BigInt::BigInt()
{
    bigint.push_back(0);
}

BigInt::BigInt(const int64_t number)
{
    sign_negative = number < 0;
    int64_t unsigned_number = abs(number);
    if (number == 0)
    {
        BigInt();
    }
    else
    {
        while (unsigned_number > 0)
        {
            bigint.push_back(static_cast<uint8_t>(unsigned_number % 10));
            unsigned_number /= 10;
        }
    }
}

BigInt::BigInt(const string &number)
{
    sign_negative = (number[0] == '-');
    bool sign_entered = (sign_negative || number[0] == '+');
    int start = 0;
    if (number.size() == 1 && sign_entered)
    {
        throw invalid_argument("Invalid integer. The sign of the number only was entered. No integer was entered");
    }
    if (sign_entered)
    {
        start = 1;
    }
    for (size_t i = number.size() - 1; i >= start; i++)
    {
        if (!((number[i] - '0' <= 9) && (number[i] - '0' >= 0)))
        {
            throw invalid_argument("Invalid Integer. A non-digit value was entered. Please enter only digits from 0-9");
        }
        bigint.push_back(static_cast<uint8_t>(number[i]));
        if (i == 0)
        {
            break;
        }
    }
}

BigInt::BigInt(const BigInt &number) : bigint(number.bigint), sign_negative(number.sign_negative) {}

size_t BigInt::getSize() const
{

    return bigint.size();
}

bool BigInt::signNegative() const
{
    // returns True if number is negative and false if positive
    return sign_negative;
}

uint8_t BigInt::getElement(const size_t i) const
{
    return bigint.at(i);
}

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
            return false;
        }
        if (i == 0)
        {
            break;
        }
    }
    return true;
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
    if (lhs.signNegative() != rhs.signNegative())
    {
        return (lhs.signNegative());
    }
    if (lhs.getSize() != rhs.getSize())
    {
        return (lhs.getSize() < rhs.getSize());
    }
    for (size_t i = lhs.getSize() - 1; i >= 0; i--)
    {
        if (lhs.getElement(i) != rhs.getElement(i))
        {
            return (!lhs.signNegative() ^ (lhs.getElement(i) < rhs.getElement(i)));
        }
        if (i == 0)
        {
            break;
        }
    }
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

    if (sign_negative == rhs.sign_negative)
    {
        *this = AbsoluteAddition(rhs);
    }
    else if (compareAbsoluteValues(rhs))
    {
        *this = AbsoluteSubtraction(rhs);
    }
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
    if (sign_negative != rhs.sign_negative)
    {
        *this = AbsoluteAddition(rhs);
    }
    else if (compareAbsoluteValues(rhs))
    {
        *this = AbsoluteSubtraction(rhs);
    }
    else
    {
        BigInt result(rhs);
        *this = result.AbsoluteSubtraction(*this);
        sign_negative = !sign_negative;
    }

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

BigInt &BigInt::operator=(const BigInt &number)
{
    sign_negative = number.signNegative();
    copyElements(number);

    return *this;
}

BigInt &BigInt::operator=(const int64_t number)
{
    BigInt temp(number);
    sign_negative = temp.signNegative();
    copyElements(temp);

    return *this;
}

BigInt &BigInt::operator=(const string &number)
{
    BigInt temp(number);
    sign_negative = temp.signNegative();
    copyElements(temp);
    return *this;
}

void BigInt::copyElements(const BigInt &rhs)
{
    bigint.resize(rhs.getSize());
    for (size_t i = 0; i < rhs.getSize(); i++)
    {
        bigint[i] = rhs.getElement(i);
    }
}

BigInt &BigInt::operator*=(const BigInt &rhs)
{
    // Initialize result with zero
    BigInt result;

    result.sign_negative = (!(sign_negative == rhs.sign_negative));

    // Perform multiplication digit by digit
    for (size_t i = 0; i < bigint.size(); i++)
    {
        uint8_t carry = 0;
        for (size_t j = 0; j < rhs.bigint.size() || carry; j++)
        {
            if (j == result.bigint.size())
                result.bigint.push_back(0);

            uint64_t current = result.bigint[i + j] +
                               static_cast<uint64_t>(bigint[i]) * (j < rhs.bigint.size() ? rhs.bigint[j] : 0) + carry;
            result.bigint[i + j] = static_cast<uint8_t>(current % 10);
            carry = static_cast<uint8_t>(current / 10);
        }
    }

    // Remove leading zeros
    while (result.bigint.size() > 1 && result.bigint.back() == 0)
    {
        result.bigint.pop_back();
    }

    *this = result;
    return *this;
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

    int carry = 0;
    for (size_t i = 0; i < maxLen || carry; ++i)
    {
        int sum = bigint[i] + carry;
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
    size_t maxLen = max(bigint.size(), rhs.getSize());

    // Ensure enough space in the result vector
    bigint.resize(maxLen + 1, 0);

    uint8_t carry = 0;
    for (size_t i = 0; i < bigint.size(); ++i)
    {
        uint8_t difference = bigint[i];
        if (i < rhs.getSize())
            difference -= rhs.getElement(i);

        if (difference < 0)
        {
            difference += 10;
            bigint[i + 1] -= 1;
        }

        bigint[i] = difference;
    }

    // Remove leading zeros
    while (bigint.size() > 1 && bigint.back() == 0)
    {
        bigint.pop_back();
    }

    return *this;
}
ostream &operator<<(ostream &out, const BigInt &bigint)
{
    if (bigint.signNegative() && (!(bigint.getSize() == 1 && bigint.getElement(0) == 0)))
    {
        out << '-';
    }
    for (size_t i = bigint.getSize() - 1; i > 0; i--)
    {
        out << bigint.getElement(i);
    }
    out << bigint.getElement(0);

    return out;
}
