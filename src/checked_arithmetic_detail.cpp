// Copyright (c) 2013, Matthew Harvey. All rights reserved.

#include "detail/checked_arithmetic_detail.hpp"

namespace jewel
{

namespace detail
{

bool CheckedArithmetic::addition_is_unsafe(int x, int y)
{
	return addition_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(long x, long y)
{
	return addition_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(long long x, long long y)
{
	return addition_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(short x, short y)
{
	return addition_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(signed char x, signed char y)
{
	return addition_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(unsigned int x, unsigned int y)
{
	return addition_is_unsafe_unsigned_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(unsigned long x, unsigned long y)
{
	return addition_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::addition_is_unsafe
(	unsigned long long x,
	unsigned long long y
)
{
	return addition_is_unsafe_unsigned_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(unsigned short x, unsigned short y)
{
	return addition_is_unsafe_unsigned_integral_types(x, y);
}

bool CheckedArithmetic::addition_is_unsafe(unsigned char x, unsigned char y)
{
	return addition_is_unsafe_unsigned_integral_types(x, y);
}

bool CheckedArithmetic::subtraction_is_unsafe(int x, int y)
{
	return subtraction_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::subtraction_is_unsafe(long x, long y)
{
	return subtraction_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::subtraction_is_unsafe(long long x, long long y)
{
	return subtraction_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::subtraction_is_unsafe(short x, short y)
{
	return subtraction_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::subtraction_is_unsafe(signed char x, signed char y)
{
	return subtraction_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::subtraction_is_unsafe(unsigned int x, unsigned int y)
{
	return subtraction_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::subtraction_is_unsafe(unsigned long x, unsigned long y)
{
	return subtraction_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::subtraction_is_unsafe
(	unsigned long long x,
	unsigned long long y
)
{
	return subtraction_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::subtraction_is_unsafe(unsigned short x, unsigned short y)
{
	return subtraction_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::subtraction_is_unsafe(unsigned char x, unsigned char y)
{
	return subtraction_is_unsafe_unsigned_integral_types(x, y);
}

bool CheckedArithmetic::multiplication_is_unsafe(int x, int y)
{
	return multiplication_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::multiplication_is_unsafe(long x, long y)
{
	return multiplication_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::multiplication_is_unsafe
(	long long x,
	long long y
)
{
	return multiplication_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::multiplication_is_unsafe(short x, short y)
{
	return multiplication_is_unsafe_signed_integral_types(x, y);
}

bool CheckedArithmetic::multiplication_is_unsafe(signed char x, signed char y)
{
	return multiplication_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::multiplication_is_unsafe(unsigned int x, unsigned int y)
{
	return multiplication_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::multiplication_is_unsafe(unsigned long x, unsigned long y)
{
	return multiplication_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::multiplication_is_unsafe
(	unsigned long long x,
 	unsigned long long y
)
{
	return multiplication_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::
  multiplication_is_unsafe(unsigned short x, unsigned short y)
{
	return multiplication_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::
  multiplication_is_unsafe(unsigned char x, unsigned char y)
{
	return multiplication_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(int x, int y)
{
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(long x, long y)
{
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(long long x, long long y)
{
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(short x, short y)
{
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(signed char x, signed char y)
{
	return division_is_unsafe_signed_integral_types(x, y);
}
	
bool
CheckedArithmetic::division_is_unsafe(unsigned int x, unsigned int y)
{
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(unsigned long x, unsigned long y)
{
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe
(	unsigned long long x,
	unsigned long long y
)
{
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(unsigned short x, unsigned short y)
{
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::division_is_unsafe(unsigned char x, unsigned char y)
{
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(int x, int y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(long x, long y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(long long x, long long y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(short x, short y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_signed_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(signed char x, signed char y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_signed_integral_types(x, y);
}
	
bool
CheckedArithmetic::remainder_is_unsafe(unsigned int x, unsigned int y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(unsigned long x, unsigned long y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe
(	unsigned long long x,
	unsigned long long y
)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(unsigned short x, unsigned short y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_unsigned_integral_types(x, y);
}

bool
CheckedArithmetic::remainder_is_unsafe(unsigned char x, unsigned char y)
{
	// Conditions for remainder operation safety are identical to those
	// of division operation safety.
	return division_is_unsafe_unsigned_integral_types(x, y);
}




}  // namespace detail

}  // namespace jewel

