# Arbitrary-Precision-Integers

Arbitrary Precision Integers C++ Class. Final Project for CSE701 - Foundations of Modern Scientific Programming Graduate Course.

In scientific Computing, We usually have to deal with large values which surpass the scope and the allocated space of conventional data types. While some programming languages handle this automatically such as Python, C++ doesn't include such functionality. C++ is one of the most known languages in Scientific Computing, providing the developer with control without sacrificing performance. Therefore, this project presents Arbitrary Precision Integers library for C++ to accommodate the scale of Scientific Computation using C++. The library allows the user to define arbitrary length integers and perform the well-known integer operations as addition, subtraction, negation, and comparison.


## Class Implementation

The library currently contains one class - BigInt, which can take an input integer or string and convert them into an arbitrary precision integer by storing them into a vector and preserving the integer sign as a boolean.

### Private Variables 
The BigInt Class has two private variables:
1. A vector of unsigned 8-bit integers to store the arbitrary precision integer.
```cpp
    vector<uint8_t> bigint;
```
2. A boolean variable to save the sign of the integer. It evaluates to True when the integer is negative and False when it's positive.
```cpp
    bool sign_negative = false;
```

### Public Functions

#### Constructors 
The BigInt Class can be defined using four types of constructors

1. **Empty Constructor:** when the user doesn't initialize the class object with a value. The empty constructor initializes the BigInt class with a vector of size 1 containing only the 0 digit and the sign as positive.

```cpp
    BigInt();
```

2. **Constructor with int:** takes a 64-bit integer as an input and converts it into a BigInt. The integer sign is saved in the `sign_negative` variable.

```cpp
    BigInt(const int64_t number);
```

3. **Constructor with string:** Takes a string of arbitrary length as input, converts the digits in the string to integers which are saved into the bigint vector to build BigInt. The function contains error checking and handling to prevent empty strings, strings with only the sign, and strings containing non-digit characters.

```cpp
    BigInt(const string &number);
```
4. **Constructor of another BigInt instance:** Takes a BigInt instances and builds another BigInt instance identical to it.

```cpp
    BigInt(const BigInt &);
```

#### Arithmetic Operations


Includes defining and overloading arithmetic operations.

1. **Addition**
2. **Subtraction**
3. **Multiplication**
4. **Negation**

```cpp
    BigInt &operator-();
    BigInt &operator+=(const BigInt &);
    BigInt &operator-=(const BigInt &);
    BigInt &operator*=(const BigInt &);
```

#### Assignment 

```cpp
    BigInt &operator=(const BigInt &bigint);
    BigInt &operator=(const int64_t number);
    BigInt &operator=(const string &number);
```


#### Helper Functions




### Class Non-member Functions

#### Insertion

```cpp
ostream &operator<<(ostream &out, const BigInt &bigint);
```

#### Overloading Arithmetic Operations

```cpp
BigInt operator+(BigInt, const BigInt &);
BigInt operator-(BigInt, const BigInt &);
BigInt operator*(BigInt , const BigInt &);
```

#### Overloading Comparison Operations
```cpp
bool operator==(const BigInt &lhs, const BigInt &rhs);
bool operator!=(const BigInt &lhs, const BigInt &rhs);
bool operator>(const BigInt &lhs, const BigInt &rhs);
bool operator<(const BigInt &lhs, const BigInt &rhs);
bool operator>=(const BigInt &lhs, const BigInt &rhs);
bool operator<=(const BigInt &lhs, const BigInt &rhs);
```

### How to run demos
in the main function in demo.cpp file run `file_demo()` to read input from file and perform operations. Run `static_demo()` to run the demo with the BigInts and operations defined inside it.