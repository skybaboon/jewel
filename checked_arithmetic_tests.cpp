#include <cassert>
#include <iostream>
#include <limits>
#include <unittest++/UnitTest++.h>
#include "checked_arithmetic.hpp"


using std::cerr;
using std::cout;
using std::endl;
using std::numeric_limits;
using jewel::CheckedArithmetic;


// TEST ADDITION SAFETY CHECKERS

TEST(checked_arithmetic_addition_is_unsafe_int)
{
	// Test reaction to unsafe operations
	int i0 = INT_MAX - 3;
	int i1 = 10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::addition_is_unsafe(i1, i0));
	int i2 = INT_MAX;
	int i3 = 1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i3, i2));
	int i4 = INT_MIN + 3;
	int i5 = -10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::addition_is_unsafe(i5, i4));
	int i6 = INT_MIN;
	int i7 = -1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::addition_is_unsafe(i7, i6));
	int i8 = INT_MAX / 2;
	int i9 = INT_MAX / 4;
	i8 += i9;
	CHECK(CheckedArithmetic::addition_is_unsafe(i8, i9 + 3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i9 + 3, i8));
	int i200 = INT_MAX;
	int i201 = INT_MAX;
	CHECK(CheckedArithmetic::addition_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::addition_is_unsafe(i201, i200));

	// Test reaction to safe operations
	int i10 = 0;
	int i11 = 1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i11, i10));
	int i12 = 0;
	int i13 = -1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i13, i12));
	int i14 = INT_MAX - 10;
	int i15 = 9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i15, i14));
	int i16 = INT_MIN + 10;
	int i17 = -9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i17, i16));
	int i18 = INT_MAX / 2;
	int i19 = INT_MAX / 2;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i19, i18));
	int i20 = INT_MIN + 10;
	int i21 = -10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i20, i21));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i21, i20));	
	int i22 = INT_MAX - 10;
	int i23 = 10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i23, i22));
}
	

TEST(checked_arithmetic_addition_is_unsafe_long)
{
	// Test reaction to unsafe operations
	long i0 = LONG_MAX - 3;
	long i1 = 10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::addition_is_unsafe(i1, i0));
	long i2 = LONG_MAX;
	long i3 = 1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i3, i2));
	long i4 = LONG_MIN + 3;
	long i5 = -10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::addition_is_unsafe(i5, i4));
	long i6 = LONG_MIN;
	long i7 = -1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::addition_is_unsafe(i7, i6));
	long i8 = LONG_MAX / 2;
	long i9 = LONG_MAX / 4;
	i8 += i9;
	CHECK(CheckedArithmetic::addition_is_unsafe(i8, i9 + 3L));
	CHECK(CheckedArithmetic::addition_is_unsafe(i9 + 3L, i8));
	long i200 = LONG_MAX;
	long i201 = LONG_MAX;
	CHECK(CheckedArithmetic::addition_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::addition_is_unsafe(i201, i200));

	// Test reaction to safe operations
	long i10 = 0;
	long i11 = 1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i11, i10));
	long i12 = 0;
	long i13 = -1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i13, i12));
	long i14 = LONG_MAX - 10;
	long i15 = 9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i15, i14));
	long i16 = LONG_MIN + 10;
	long i17 = -9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i17, i16));
	long i18 = LONG_MAX / 2;
	long i19 = LONG_MAX / 2;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i19, i18));
	long i20 = LONG_MIN + 10;
	long i21 = -10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i20, i21));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i21, i20));	
	long i22 = LONG_MAX - 10;
	long i23 = 10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i23, i22));
}
	

TEST(checked_arithmetic_addition_is_unsafe_short)
{
	// Test reaction to unsafe operations
	short i0 = SHRT_MAX - 3;
	short i1 = 10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::addition_is_unsafe(i1, i0));
	short i2 = SHRT_MAX;
	short i3 = 1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i3, i2));
	short i4 = SHRT_MIN + 3;
	short i5 = -10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::addition_is_unsafe(i5, i4));
	short i6 = SHRT_MIN;
	short i7 = -1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::addition_is_unsafe(i7, i6));
	short i8 = SHRT_MAX / short(2);
	short i9 = SHRT_MAX / short(4);
	i8 += i9;
	short i9b = i9 + 3;
	CHECK(CheckedArithmetic::addition_is_unsafe(i8, i9b));
	CHECK(CheckedArithmetic::addition_is_unsafe(i9b, i8));
	short i200 = SHRT_MAX;
	short i201 = SHRT_MAX;
	CHECK(CheckedArithmetic::addition_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::addition_is_unsafe(i201, i200));

	// Test reaction to safe operations
	short i10 = 0;
	short i11 = 1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i11, i10));
	short i12 = 0;
	short i13 = -1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i13, i12));
	short i14 = SHRT_MAX - 10;
	short i15 = 9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i15, i14));
	short i16 = SHRT_MIN + 10;
	short i17 = -9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i17, i16));
	short i18 = SHRT_MAX / 2;
	short i19 = SHRT_MAX / 2;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i19, i18));
	short i20 = SHRT_MIN + 10;
	short i21 = -10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i20, i21));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i21, i20));	
	short i22 = SHRT_MAX - 10;
	short i23 = 10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i23, i22));
}

	

TEST(checked_arithmetic_addition_is_unsafe_unsigned_int)
{
	// Test reaction to unsafe operations
	unsigned int i0 = UINT_MAX - 3;
	unsigned int i1 = 10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::addition_is_unsafe(i1, i0));
	unsigned int i2 = UINT_MAX;
	unsigned int i3 = 1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i3, i2));
	unsigned int i8 = UINT_MAX / 2;
	unsigned int i9 = UINT_MAX / 4;
	i8 += i9;
	CHECK(CheckedArithmetic::addition_is_unsafe(i8, i9 + 3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i9 + 3, i8));
	unsigned int i200 = UINT_MAX;
	unsigned int i201 = UINT_MAX;
	CHECK(CheckedArithmetic::addition_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::addition_is_unsafe(i201, i200));

	// Test reaction to safe operations
	unsigned int i10 = 0;
	unsigned int i11 = 1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i11, i10));
	unsigned int i14 = UINT_MAX - 10;
	unsigned int i15 = 9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i15, i14));
	unsigned int i18 = UINT_MAX / 2;
	unsigned int i19 = UINT_MAX / 2;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i19, i18));
	unsigned int i22 = UINT_MAX - 10;
	unsigned int i23 = 10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i23, i22));
}
	

TEST(checked_arithmetic_addition_is_unsafe_unsigned_long)
{
	// Test reaction to unsafe operations
	unsigned long i0 = ULONG_MAX - 3;
	unsigned long i1 = 10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::addition_is_unsafe(i1, i0));
	unsigned long i2 = ULONG_MAX;
	unsigned long i3 = 1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i3, i2));
	unsigned long i8 = ULONG_MAX / 2;
	unsigned long i9 = ULONG_MAX / 4;
	i8 += i9;
	CHECK(CheckedArithmetic::addition_is_unsafe(i8, i9 + 3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i9 + 3, i8));
	unsigned long i200 = ULONG_MAX;
	unsigned long i201 = ULONG_MAX;
	CHECK(CheckedArithmetic::addition_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::addition_is_unsafe(i201, i200));

	// Test reaction to safe operations
	unsigned long i10 = 0;
	unsigned long i11 = 1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i11, i10));
	unsigned long i14 = ULONG_MAX - 10;
	unsigned long i15 = 9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i15, i14));
	unsigned long i18 = ULONG_MAX / 2;
	unsigned long i19 = ULONG_MAX / 2;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i19, i18));
	unsigned long i22 = ULONG_MAX - 10;
	unsigned long i23 = 10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i23, i22));
}
	

TEST(checked_arithmetic_addition_is_unsafe_unsigned_short)
{
	// Test reaction to unsafe operations
	unsigned short i0 = USHRT_MAX - 3;
	unsigned short i1 = 10;
	CHECK(CheckedArithmetic::addition_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::addition_is_unsafe(i1, i0));
	unsigned short i2 = USHRT_MAX;
	unsigned short i3 = 1;
	CHECK(CheckedArithmetic::addition_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::addition_is_unsafe(i3, i2));
	unsigned short i8 = USHRT_MAX / 2;
	unsigned short i9 = USHRT_MAX / 4;
	i8 += i9;
	unsigned short i9b = i9 + 3;
	CHECK(CheckedArithmetic::addition_is_unsafe(i8, i9b));
	CHECK(CheckedArithmetic::addition_is_unsafe(i9b, i8));
	unsigned short i200 = USHRT_MAX;
	unsigned short i201 = USHRT_MAX;
	CHECK(CheckedArithmetic::addition_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::addition_is_unsafe(i201, i200));

	// Test reaction to safe operations
	unsigned short i10 = 0;
	unsigned short i11 = 1;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i11, i10));
	unsigned short i14 = USHRT_MAX - 10;
	unsigned short i15 = 9;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i15, i14));
	unsigned short i18 = USHRT_MAX / 2;
	unsigned short i19 = USHRT_MAX / 2;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i19, i18));
	unsigned short i22 = USHRT_MAX - 10;
	unsigned short i23 = 10;
	CHECK(!CheckedArithmetic::addition_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::addition_is_unsafe(i23, i22));
}
	

// TEST SUBTRACTION SAFETY CHECKERS


TEST(checked_arithmetic_subtraction_is_unsafe_int)
{
	// Test reaction to unsafe operations
	int i0 = INT_MAX - 3;
	int i1 = -10;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i1, i0));
	int i2 = INT_MAX;
	int i3 = -2;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i3, i2));
	int i4 = INT_MIN + 3;
	int i5 = 10;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i5, i4));
	int i6 = INT_MIN;
	int i7 = 1;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i7, i6));

	// Test reaction to safe operations
	int i10 = 0;
	int i11 = -1;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i11, i10));
	int i12 = 0;
	int i13 = 1;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i13, i12));
	int i14 = INT_MAX - 10;
	int i15 = -9;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i15, i14));
	int i16 = INT_MIN + 10;
	int i17 = 9;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i17, i16));
	int i18 = INT_MAX / 2;
	int i19 = -(INT_MAX / 2);
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i19, i18));
	int i20 = INT_MIN + 10;
	int i21 = 10;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i20, i21));
	int i22 = INT_MAX - 10;
	int i23 = -10;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i23, i22));
	int i24 = -INT_MAX;
	int i25 = 1;
	// Remember the absolute value of INT_MAX is 1 less than that
	// of INT_MIN - so the following operation should be safe
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i24, i25));
}
	

TEST(checked_arithmetic_subtraction_is_unsafe_long)
{
	// Test reaction to unsafe operations
	long i0 = LONG_MAX - 3;
	long i1 = -10;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i1, i0));
	long i2 = LONG_MAX;
	long i3 = -2;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i3, i2));
	long i4 = LONG_MIN + 3;
	long i5 = 10;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i5, i4));
	long i6 = LONG_MIN;
	long i7 = 1;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i7, i6));

	// Test reaction to safe operations
	long i10 = 0;
	long i11 = -1;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i11, i10));
	long i12 = 0;
	long i13 = 1;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i13, i12));
	long i14 = LONG_MAX - 10;
	long i15 = -9;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i15, i14));
	long i16 = LONG_MIN + 10;
	long i17 = 9;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i17, i16));
	long i18 = LONG_MAX / 2;
	long i19 = -(LONG_MAX / 2);
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i19, i18));
	long i20 = LONG_MIN + 10;
	long i21 = 10;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i20, i21));
	long i22 = LONG_MAX - 10;
	long i23 = -10;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i23, i22));
	long i24 = -LONG_MAX;
	long i25 = 1;
	// Remember the absolute value of LONG_MAX is 1 less than that
	// of LONG_MIN - so the following operation should be safe
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i24, i25));
}
	
TEST(checked_arithmetic_subtraction_is_unsafe_short)
{
	// Test reaction to unsafe operations
	short i0 = SHRT_MAX - 3;
	short i1 = -10;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i1, i0));
	short i2 = SHRT_MAX;
	short i3 = -2;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i3, i2));
	short i4 = SHRT_MIN + 3;
	short i5 = 10;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i5, i4));
	short i6 = SHRT_MIN;
	short i7 = 1;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i7, i6));

	// Test reaction to safe operations
	short i10 = 0;
	short i11 = -1;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i10, i11));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i11, i10));
	short i12 = 0;
	short i13 = 1;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i13, i12));
	short i14 = SHRT_MAX - 10;
	short i15 = -9;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i15, i14));
	short i16 = SHRT_MIN + 10;
	short i17 = 9;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i17, i16));
	short i18 = SHRT_MAX / 2;
	short i19 = -(SHRT_MAX / 2);
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i19, i18));
	short i20 = SHRT_MIN + 10;
	short i21 = 10;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i20, i21));
	short i22 = SHRT_MAX - 10;
	short i23 = -10;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i22, i23));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i23, i22));
	short i24 = -SHRT_MAX;
	short i25 = 1;
	// Remember the absolute value of SHRT_MAX is 1 less than that
	// of SHRT_MIN - so the following operation should be safe
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i24, i25));
}
	

TEST(checked_arithmetic_subtraction_is_unsafe_unsigned_int)
{
	// Test reaction to unsafe operations
	unsigned int i0 = 0;
	unsigned int i1 = 1;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i0, i1));
	unsigned int i2 = 1020;
	unsigned int i3 = 32342;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i2, i3));
	unsigned int i4 = UINT_MAX - 1;
	unsigned int i5 = UINT_MAX;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i4, i5));
	
	// Test reaction to safe operations
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i1, i0));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i3, i2));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i5, i4));
	unsigned int k1 = 0;
	unsigned int k2 = 0;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(k1, k2));
	unsigned int k3 = UINT_MAX;
	unsigned int k4 = UINT_MAX;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(k3, k4));
}

TEST(checked_arithmetic_subtraction_is_unsafe_unsigned_long)
{
	// Test reaction to unsafe operations
	unsigned long i0 = 0;
	unsigned long i1 = 1;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i0, i1));
	unsigned long i2 = 1020;
	unsigned long i3 = 32342;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i2, i3));
	unsigned long i4 = ULONG_MAX - 1;
	unsigned long i5 = ULONG_MAX;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i4, i5));
	
	// Test reaction to safe operations
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i1, i0));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i3, i2));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i5, i4));
	unsigned long k1 = 0;
	unsigned long k2 = 0;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(k1, k2));
	unsigned long k3 = ULONG_MAX;
	unsigned long k4 = ULONG_MAX;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(k3, k4));
}

TEST(checked_arithmetic_subtraction_is_unsafe_unsigned_short)
{
	// Test reaction to unsafe operations
	unsigned short i0 = 0;
	unsigned short i1 = 1;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i0, i1));
	unsigned short i2 = 1020;
	unsigned short i3 = 32342;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i2, i3));
	unsigned short i4 = USHRT_MAX - 1;
	unsigned short i5 = USHRT_MAX;
	CHECK(CheckedArithmetic::subtraction_is_unsafe(i4, i5));
	
	// Test reaction to safe operations
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i1, i0));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i3, i2));
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(i5, i4));
	unsigned short k1 = 0;
	unsigned short k2 = 0;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(k1, k2));
	unsigned short k3 = USHRT_MAX;
	unsigned short k4 = USHRT_MAX;
	CHECK(!CheckedArithmetic::subtraction_is_unsafe(k3, k4));
}


// TEST MULTIPLICATION SAFETY CHECKERS

TEST(checked_arithmetic_multiplication_is_unsafe_int)
{
	// Test reaction to unsafe operations
	int i0 = 3;
	int i1 = INT_MAX / 2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i1, i0));
	int i2 = 3;
	int i3 = INT_MIN / -2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i3, i2));
	int i4 = INT_MAX / 10;
	int i5 = -500;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i5, i4));
	int i6 = INT_MAX - 1;
	int i7 = INT_MAX - 1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i7, i6));
	int i8 = INT_MIN;
	int i9 = INT_MAX;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i8, i9));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i9, i8));
	int i10 = INT_MIN / 20;
	int i11 = 30;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i10, i11));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i11, i10));
	int i200 = INT_MIN;
	int i201 = -1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i201, i200));
	int i202 = INT_MIN;
	int i203 = -2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i202, i203));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i203, i202));
	
	// Test reaction to safe operations
	int i12 = 0;
	int i13 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i13, i12));
	int i14 = -0;
	int i15 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i15, i14));
	int i16 = 1023;
	int i17 = 123;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i17, i16));
	int i18 = INT_MAX;
	int i19 = -1;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i18, i19));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i19, i18));
	int i20 = INT_MIN;
	int i21 = 1;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i20, i21));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i21, i20));
	int i22 = INT_MAX / 6;
	int i26 = 6;
	int i27 = -5;
	int i28 = -6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i22, i26));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i22, i27));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i22, i28));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i26, i22));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i27, i22));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i28, i22));
	int i29 = INT_MIN / 2;
	int i31 = 2;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i29, i31));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i31, i29));
	int i32 = 1000;
	int i33 = 14;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i32, i33));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i33, i32));
	int i34 = INT_MAX / 10;
	int i35 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i34, i35));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i35, i34));
	int i36 = INT_MIN / 10;
	int i37 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i36, i37));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i37, i36));
}

TEST(checked_arithmetic_multiplication_is_unsafe_long)
{
	// Test reaction to unsafe operations
	long i0 = 3;
	long i1 = LONG_MAX / 2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i1, i0));
	long i2 = 3;
	long i3 = LONG_MIN / -2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i3, i2));
	long i4 = LONG_MAX / 10;
	long i5 = -500;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i5, i4));
	long i6 = LONG_MAX - 1;
	long i7 = LONG_MAX - 1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i7, i6));
	long i8 = LONG_MIN;
	long i9 = LONG_MAX;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i8, i9));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i9, i8));
	long i10 = LONG_MIN / 20;
	long i11 = 30;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i10, i11));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i11, i10));
	long i200 = LONG_MIN;
	long i201 = -1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i201, i200));
	long i202 = LONG_MIN;
	long i203 = -2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i202, i203));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i203, i202));
	
	// Test reaction to safe operations
	long i12 = 0;
	long i13 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i13, i12));
	long i14 = -0;
	long i15 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i15, i14));
	long i16 = 1023;
	long i17 = 123;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i17, i16));
	long i32 = 1000;
	long i33 = 14;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i32, i33));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i33, i32));
	long i34 = LONG_MAX / 10;
	long i35 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i34, i35));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i35, i34));
	long i36 = LONG_MIN / 10;
	long i37 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i36, i37));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i37, i36));
}

TEST(checked_arithmetic_multiplication_is_unsafe_short)
{
	// Test reaction to unsafe operations
	short i0 = 3;
	short i1 = SHRT_MAX / 2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i1, i0));
	short i2 = 3;
	short i3 = SHRT_MIN / -2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i2, i3));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i3, i2));
	short i4 = SHRT_MAX / 10;
	short i5 = -500;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i5, i4));
	short i6 = SHRT_MAX - 1;
	short i7 = SHRT_MAX - 1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i7, i6));
	short i8 = SHRT_MIN;
	short i9 = SHRT_MAX;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i8, i9));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i9, i8));
	short i10 = SHRT_MIN / 20;
	short i11 = 30;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i10, i11));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i11, i10));
	short i200 = SHRT_MIN;
	short i201 = -1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i200, i201));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i201, i200));
	short i202 = SHRT_MIN;
	short i203 = -2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i202, i203));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i203, i202));
	
	// Test reaction to safe operations
	short i12 = 0;
	short i13 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i13, i12));
	short i14 = -0;
	short i15 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i14, i15));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i15, i14));
	short i16 = -12;
	short i17 = 13;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i16, i17));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i17, i16));
	short i32 = 100;
	short i33 = 14;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i32, i33));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i33, i32));
	short i34 = SHRT_MAX / 10;
	short i35 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i34, i35));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i35, i34));
	short i36 = SHRT_MIN / 10;
	short i37 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i36, i37));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i37, i36));
}

TEST(checked_arithmetic_multiplication_is_unsafe_unsigned_int)
{
	// Test reaction to unsafe operations
	unsigned int i0 = 3;
	unsigned int i1 = UINT_MAX / 2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i1, i0));
	unsigned int i4 = UINT_MAX / 10;
	unsigned int i5 = 15;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i5, i4));
	unsigned int i6 = UINT_MAX - 1;
	unsigned int i7 = UINT_MAX - 1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i7, i6));
	unsigned int i8 = UINT_MAX;
	unsigned int i9 = UINT_MAX;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i8, i9));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i9, i8));
	unsigned int i10 = UINT_MAX / 20;
	unsigned int i11 = 30;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i10, i11));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i11, i10));
	
	// Test reaction to safe operations
	unsigned int i12 = 0;
	unsigned int i13 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i13, i12));
	unsigned int i32 = 100;
	unsigned int i33 = 14;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i32, i33));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i33, i32));
	unsigned int i34 = UINT_MAX / 10;
	unsigned int i35 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i34, i35));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i35, i34));
	unsigned int i36 = 100;
	unsigned int i37 = 30;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i36, i37));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i37, i36));
}

TEST(checked_arithmetic_multiplication_is_unsafe_unsigned_long)
{
	// Test reaction to unsafe operations
	unsigned long i0 = 3;
	unsigned long i1 = ULONG_MAX / 2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i1, i0));
	unsigned long i4 = ULONG_MAX / 10;
	unsigned long i5 = 15;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i5, i4));
	unsigned long i6 = ULONG_MAX - 1;
	unsigned long i7 = ULONG_MAX - 1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i7, i6));
	unsigned long i8 = ULONG_MAX;
	unsigned long i9 = ULONG_MAX;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i8, i9));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i9, i8));
	unsigned long i10 = ULONG_MAX / 20;
	unsigned long i11 = 30;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i10, i11));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i11, i10));
	
	// Test reaction to safe operations
	unsigned long i12 = 0;
	unsigned long i13 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i13, i12));
	unsigned long i32 = 100;
	unsigned long i33 = 14;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i32, i33));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i33, i32));
	unsigned long i34 = ULONG_MAX / 10;
	unsigned long i35 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i34, i35));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i35, i34));
	unsigned long i36 = 100;
	unsigned long i37 = 30;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i36, i37));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i37, i36));
}

TEST(checked_arithmetic_multiplication_is_unsafe_unsigned_short)
{
	// Test reaction to unsafe operations
	unsigned short i0 = 3;
	unsigned short i1 = USHRT_MAX / 2;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i0, i1));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i1, i0));
	unsigned short i4 = USHRT_MAX / 10;
	unsigned short i5 = 15;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i4, i5));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i5, i4));
	unsigned short i6 = USHRT_MAX - 1;
	unsigned short i7 = USHRT_MAX - 1;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i6, i7));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i7, i6));
	unsigned short i8 = USHRT_MAX;
	unsigned short i9 = USHRT_MAX;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i8, i9));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i9, i8));
	unsigned short i10 = USHRT_MAX / 20;
	unsigned short i11 = 30;
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i10, i11));
	CHECK(CheckedArithmetic::multiplication_is_unsafe(i11, i10));
	
	// Test reaction to safe operations
	unsigned short i12 = 0;
	unsigned short i13 = 0;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i12, i13));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i13, i12));
	unsigned short i32 = 100;
	unsigned short i33 = 14;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i32, i33));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i33, i32));
	unsigned short i34 = USHRT_MAX / 10;
	unsigned short i35 = 6;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i34, i35));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i35, i34));
	unsigned short i36 = 100;
	unsigned short i37 = 30;
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i36, i37));
	CHECK(!CheckedArithmetic::multiplication_is_unsafe(i37, i36));
}




