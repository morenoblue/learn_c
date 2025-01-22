===========================================================================================================
# Undefined vs Unspecified vs Implementation-defined Behaviours


- Undefined -> We have no idea about what will happen. There are no guarantees. The program is most
               likely to crash. These are your classic memory accesses outside of array bounds, signed
               integer overflow, null pointer dereference, modification of the same scalar more than once
               in an expression without sequence points, access to an object through a pointer of a different
               type, etc. (3.4.3)


- Unspecified -> Theres a couple possible options in which something may happen in a certain situation
                 but the implementation is not required to document in which way will it go. For example,
                 order of evaluation, whether identical string literals are distinct, etc. Each
                 unspecified behavior results in one of a set of valid results and may produce
                 a different result when repeated in the same program. (3.4.4)

- Implementation-Defined -> Same as unspecified but the implementation actually needs to document in which
                            way something will go. (3.4.1)


- Locale-Defined -> Behavior that depends on local conventions of nationality, culture, and language that
                    each implementation documents. (3.4.2)


============================================================================================================
# What is an Expression?

An Expression (6.5) everything below:

1. a sequence of operators and their operands that specify a value computation;
2. a sequence of operators and their operands that specify a value computation and a side effect;
3. a function call;
4. the combination of all of the above points 1-3.

In other words in C an Expression is essentially -> an operator with its arguments, a function call, a constant, a variable name, etc


============================================================================================================
# What are the properties of an expression?

- Type (6.2.5)
    
- Value Category (6.3.2.1)
    - lvalue (left value)
    - non-lvalue or rvalue (right value)
    - function designator


============================================================================================================
# What is an lvalue?

(6.3.2.1) Any Expression with an object type which potentially designates an
object. (If the lvalue doesn't designate an object, then its causes undefined
behavior when it is evaluated. One example of this might be dereferencing an
uninitialized pointer). When an object is said to have a particular type, the
type is specified by the lvalue used to designate the object.


===========================================================================================================
# What is a modifiable lvalue?

(6.3.2.1) A modifiable lvalue is an lvalue that does not have array type, does
not have an incomplete type, does not have a const-qualified type, and if it is a structure
or union, does not have any member (including, recursively, any member or element of
all contained aggregates or unions) with a const-qualified type


===========================================================================================================
            # What are some of the contexts in which lvalues can be used?

(6.3.2.1)
lvalues expressions can used in the following contexts:
    
    - as the left operand of the assignment operator. (or compound assignment)
    - as the left operand of the member access operator (dot) 
    - as the operand of the address of operator (&)
    - as the operand of the pre/post increment or decrement operators

    * Aside from the sizeof and _Alignof operators as well as
    aside from the 4 points mentioned above, the evaluation of a
    non-array lvalue will cause something called lvalue
    conversion in which the lvalue gets converted to its object identity value.

    * The evaluation of an array lvalues though will cause
    something called lvalue-to-pointer conversion in which the
    lvalue gets converted to a pointer pointing to the first
    element of the array list.


===========================================================================================================
# Use your brain to identify a couple lvalues

(6.3.2.1)
The following are lvalues:

    - Identifiers including function named parameters: For example, int x = 5; x = 10; where x is an lvalue.

    - Parenthesized expression if the unparenthesized expression is an lvalue: For example, (int& y = x); y = 10; where y is an lvalue.

    - The result of a member access operator if the left operand is an lvalue: For example, obj.value = 5; where obj.value is an lvalue.

    - The result of the subscription operator ([]): For example, arr[2] = 10; where arr[2] is an lvalue.

    - The result of the indirection operator (*) applied to a pointer: For example, *ptr = 10; where *ptr is an lvalue.

    - The result of a member access through the pointer operator (->): For example, ptr->value = 5; where ptr->value is an lvalue.

    - A string literal: For example, str = "World"; where str is an lvalue (pointer to a string literal).

    - A compound literal: For example, (int){10} = 20; where the compound literal is an lvalue.


===========================================================================================================
# Use your brain to identify a couple rvalues

(6.3.2.1)
The following are considered rvalue expressions:

        - Integer, character, and floating constants: For example, 5, 'a', 3.14 are rvalues.

        - The result of the assignment operator: For example, x = 10; where the result of the assignment is an rvalue.

        - The result of the member access operator if the operand to the left side of it is not an lvalue: For example, f().x, (x,s1).a, (s1 = s2).m are rvalues.

        - The result of the assignment operator: For example, (s1 = s2).m where the result is an rvalue.

        - The result of the decrement/increment operators: For example, ++x or x++ where the result is an rvalue.

        - The result of the comma operator: For example, (x, y) where the result is the value of y, an rvalue.

        - The result of the conditional operator: For example, x ? 10 : 20 where the result is an rvalue.

        - String literals: For example, "Hello" is an rvalue (pointer to a string literal).

        - Compound literals: For example, (int){10} is an rvalue.


===========================================================================================================
# What is a function designator?

(6.3.2.1)
A function designator is an expression that has function type.

* the use of a function designator always gets coverted to a
  rvalue pointer to function (except in sizeof and
  _Alignof). Also, notice that the call operator of a function "()" only
  operates on the pointer to function object.


===========================================================================================================
# Expressions vs Statements

Expressions (6.5): Something that computes a value. Eg.: (1/2) + 23/(a = 2)
Statement (6.8): A line of code which does something. printf("something");

Extra: Remember, code is produced by writing statements, not expressions. The statements themselves can contain expressions, furthermore in C, you are allowed to create a statement that contains nothing else other then an expression, we call those "expression statements" and they can be created by simply adding a semicolon to the end of the expression.


===========================================================================================================
# What is the order of sub-expression evaluation?

(6.5.3)
The order of evaluation of subexpressions and the order in which side effects take
place are both unspecified. We don't know the order of sub-expression
evaluation. In the expression statement a + b; a can be executed first or b can
be executed first, we don't know.


===========================================================================================================
# What is an Objects?

(3.14)
C programs create, destroy, access and manipulate objects.

Objects are a region of data storage in the execution environment, the contents of which can represent a value.
A value is the meaning of the contents of an object when interpreted as having a specific type;


===========================================================================================================
# What are the properties of an Object?

Every Object has:

- Possibly a Identifier;
- Possibly an effective type;
- Possibly a value;
- Alignment;
- Size;
- Lifetime;
- Storage Duration;


===========================================================================================================
# What is an Object representation?

An Object is a contiguos sequence of bytes and they can be copied using memcpy
to an object of type unsigned char[N] (N is the size of the object).
The result of that array is called Object representation.

If an two objects have the same object representation, they compare equal (Except if they are floating point-NaN's).
The reverse is not true though. If two objects compare true that doesn't mean that they have the same object representation.

If the object representation does not represent any value of the object type, its called trap representation.
Accessing a trap representation in another way other than reading it is undefined behavior.

For the objects of type char, signed char, and unsigned char, every bit of the
object representation is required to participate in the value representation and
each possible bit pattern represents a distinct value (no padding, trap bits, or
multiple representations allowed).


===========================================================================================================
# What is Strict aliasing?

Given an object with effective type T1, using an lvalue expression
(typically, dereferencing a pointer) of a different type T2 is undefined
behavior, unless:

T2 and T1 are compatible types. T2 is cvr-qualified version of a type that
is compatible with T1. T2 is a signed or unsigned version of a type that is
compatible with T1. T2 is an aggregate type or union type type that includes
one of the aforementioned types among its members (including, recursively, a
member of a subaggregate or contained union). T2 is a character type (char,
signed char, or unsigned char).


===========================================================================================================
# Types

INTEGER TYPES
    Standard integer types (signed and unsigned, except for _Bool which is only unsigned): 

        _Bool (since c99); char; short; long; long long (since c99)

    Extended integer types:

        __int128  (signed)
        __uint128 (unsigned)
     
    Bit-precise inter types:

        signed _BitInt(N) (default)
        unsigned _BitInt(N) 

FLOATING TYPES
    Real floating types: float, double, long double 

    Decimal floating types: _Decimal32,_Decimal64,_Decimal128 

    Complex floating types: float _Complex, double _Complex, long double _Complex 

    Imaginary floating types: float _Imaginary, double _Imaginary, long double _Imaginary 

    
When defining them the order does not matter. For example:

    int long long = long int long = long long int 

Furthermore, when defining shorts or longs, the keyword "int" is not obligatory, in fact is more idiomatic to not include it:

    int long long = long int long = long long int = long long


According to the C standard, short <= int <= long <= long long. For example :

    16 bit computers (signed):
        
        short: -32_768 -> +32_767 (2^16)

        int: -32_768 -> +32_767 (2^16)

        long: -2_147_483_647 -> +2_147_483_647 (2^32) 

    32 bit computers (signed):
        
        short: -32_768 -> +32_767 (2^16)

        int: -2_147_483_648 -> +2_147_483_647 (2^32) 

        long: -2_147_483_648 -> +2_147_483_647 (2^32) 

    64 bit computers (signed):
        
        short: -32_768 -> +32_767 (2^16)

        int: -2_147_483_647 -> +2_147_483_647 (2^32) 

        long: -9_223_372_036_854_775_808 -> +9_223_372_036_854_775_807 (2^64) 

The examples above aren't mandatory they may vary depending on the compiler. To find out the sizes for you specific machine you can use the library <limits.h> which it provides you with macros like {TYPE}_{SIZE}, with {TYPE} in {SHRT, INT, LONG, LLONG} and {SIZE} in {MIN, MAX}.






# Constants

INTEGERS
    Decimal -> 1, 3, 5, 2, 25, 7, 358 ... (All Decimals start with any number from 1-9)
            -> If you don't use l (long int), u (unsigned int), ll (long long) 
			   or a combination of ll and u or l and u to force the constant to conform to a 
			   specific type, it will pick the smallest of the following types that can contain the constant:
			   int -> long int -> long long int 

    Octal -> 01, 03, 05, 02, 025, 07, 0358 ... (All Octals start with 0)
    Hexadecimal -> 0xff, 0x12, 0xff13 ... (All Hexadecimals start with 0x)
   │
   │
   └──> For both Octal and Hexadecimal if you don't use l (long int), u (unsigned int), ll (long long) 
        or a combination of ll and u or l and u to force the constant to conform to a 
        specific type, it will pick the smallest of the following types that can contain the constant:
        int -> unsigned int -> long -> unsigned long -> long long -> unsigned long long


FLOATS real floating point -> 57.0, 57., 57.0e0 5.7e1, .570e-1 ...(different
                                                                   ways to represent the same number: 57.0) 

                           -> Floating constants are by default
                           stored in double-precison but you can force it to be either a float by appending
                           f or F to the end of the number (eg.: 57.0f or 57.0F) or long double by
                           appending l or L (eg.: 57.0l or 57.0L).


===========================================================================================================
# What happens when integer overflow occurs?

If the ints are signed then we get undefined behaviour;

If the ints are unsigned then the result we get is the correct answer modulo 2^n
with n being the number of bits used to store the result. (modular arithmetic
remember, its also how 2's complement is described)


===========================================================================================================
# Are C bytes and storage bytes the same thing?

When I first heard this I felt bambuzled. C definition os byte does not say
anywhere that it should be 8-bits as opposed to the definition from a storage
point of view. C defines bytes as being (3.6.1) an addressable unit of data
storage large enough to hold any member of the basic character set of the
execution environment. In other words is possible than in some other system we
have bytes of other sizes like 16 for example. An example of a hardware that
usually uses bytes with more than 8 bits is a DSP.


===========================================================================================================
# IEEE vs IEC (regarding the floating point)

IEEE introduced us to the standard for the floating-point arithmetic with the
IEEE-754 but IEC is an organization that has more International Recognition and
it sometimes takes in standards from other organizations in order to further
spread it around and changes the name of the standard in the process, for
example the IEEE-754 standard was changed to IEC-60559, in otherwords whenever
you read or hear someone talking about the IEEE-754 or IEC-60559, just know that
they are talking about the same thing.


===========================================================================================================
# Relationship between the C standard and the IEEE-754

The C standard was made to be very flexible, in other words it allows you to use
it even in implementations that don't use the IEEE-754 standard. (Nowadays most
computer will follow that standard though)
