// Copyright (c) 2013, Matthew Harvey. All rights reserved.

#ifndef GUARD_capped_string_hpp
#define GUARD_capped_string_hpp

#include "smallest_sufficient_unsigned_type.hpp"
#include <jewel/log.hpp>
#include <algorithm>
#include <cstddef>
#include <istream>
#include <ostream>
#include <string>

namespace jewel
{


/**
 * A template for string classes encapsulating a limited length string of
 * \e char, which is safer than a C-style string, more convenient than a
 * boost::array<char, N> or a std::array<char, N>, and can be copied
 * safely.
 *
 * The string is limited to a certain length; but for purposes of
 * assessing the length of the string, and comparing strings with each
 * other, etc., only the characters up to null are considered relevant.
 *
 * No heap allocation is performed by CappedString.
 *
 * None of the member functions of this class will ever throw an exception.
 * (The only possible source of runtime failure is stack overflow.)
 *
 * If an attempt is made to initialize a CappedString<N> from a built-in
 * string or std::string that exceeds N in length, then the resulting
 * CappedString will be truncated relative to that original string.
 * You can tell whether a CappedString is thus truncated by calling its
 * \e is_truncated() member. Internally, CappedString will always
 * null-terminate its internal char array, even if it is truncated
 * relative to the original string.
 *
 * When comparing strings using \e operator==, truncation is ignored.
 * I.e., two CappedString<N> are considered equal if they have the
 * same char contents (in the same order), even if one is truncated and
 * the other is not.
 *
 * You can obtain a pointer to the internal null-terminated char array
 * by calling \e c_str() - with caveats as per the member function in
 * std::string of the same name.
 *
 * Note the template parameter N represents the maximum number of characters
 * in the CappedString NOT including the null-terminator (which is considered
 * an implementation detail). This is the same number that is returned by
 * the member function \e capacity().
 *
 * TODO Allow a CappedString<N> to be initialized and/or copied
 * a CappedString<M> where M != N.
 *
 * TODO Implement indexing operator functions. (Should also implement
 * at(); but note this will mean we will have to qualify blanket
 * guarantee that no member functions throw.)
 *
 * TODO HIGH PRIORITY Testing.
 */
template <std::size_t N>
class CappedString
{
public:

	typedef char const* const_iterator;
	typedef char* iterator;
	typedef typename SmallestSufficientUnsignedType<N + 1>::Result size_type;
	typedef std::ptrdiff_t difference_type;
	typedef char value_type;
	// typedef ??? const_reverse_iterator;  // TODO <---
	// typedef ??? reverse_iterator;  // TODO <---

	CappedString();
	CappedString(char const* p_string);
	explicit CappedString(std::string const& p_string);

	CappedString(CappedString const& rhs);

	// Use compiler-generated destructor.

	// TODO Up to here with unit testing.

	CappedString& operator=(CappedString const& rhs);
	bool operator==(CappedString const& rhs) const;
	bool operator!=(CappedString const& rhs) const;

	char const* c_str() const;

	size_type capacity() const;
	size_type size() const;
	bool empty() const;

	bool is_truncated() const;

	void clear();

private:

	void initialize_from_c_string(char const* p_string);
	void unchecked_assign(CappedString const& rhs);
	bool m_is_truncated;
	size_type m_len;
	char m_data[N + 1];
};


// NON-MEMBER FUNCTIONS

/**
 * Write to an output stream.
 */
template <typename traits, std::size_t N>
std::basic_ostream<typename CappedString<N>::value_type, traits>&
operator<<
(	std::basic_ostream<typename CappedString<N>::value_type, traits>& p_os,
	CappedString<N> const& p_str
);

/**
 * Read from an output stream.
 *
 * TODO Implement this.
 */
template <typename traits, std::size_t N>
std::basic_istream<typename CappedString<N>::value_type, traits>&
operator>>
(	std::basic_istream<typename CappedString<N>::value_type, traits> p_is,
	CappedString<N> const& p_str
);



// FUNCTION IMPLEMENTATIONS

template <std::size_t N>
inline
CappedString<N>::CappedString(): m_is_truncated(false), m_len(0)
{
	*m_data = '\0';
}

template <std::size_t N>
inline
CappedString<N>::CappedString(char const* p_string)
{
	initialize_from_c_string(p_string);
}

template <std::size_t N>
inline
CappedString<N>::CappedString(std::string const& p_string)
{
	initialize_from_c_string(p_string.c_str());
}

template <std::size_t N>
inline
CappedString<N>::CappedString(CappedString const& rhs)
{
	unchecked_assign(rhs);
}

template <std::size_t N>
inline
CappedString<N>&
CappedString<N>::operator=(CappedString const& rhs)
{
	if (&rhs != this) unchecked_assign(rhs);
	return *this;
}

template <std::size_t N>
inline
bool
CappedString<N>::operator==(CappedString const& rhs) const
{
	return
	(	(m_len == rhs.m_len) &&
		std::equal(m_data, m_data + m_len, rhs.m_data)
	);
}

template <std::size_t N>
inline
bool
CappedString<N>::operator!=(CappedString const& rhs) const
{
	return !(*this == rhs);
}

template <std::size_t N>
inline
char const*
CappedString<N>::c_str() const
{
	return m_data;
}

template <std::size_t N>
inline
typename CappedString<N>::size_type
CappedString<N>::capacity() const
{
	return static_cast<size_type>(N);
}

template <std::size_t N>
inline
typename CappedString<N>::size_type
CappedString<N>::size() const
{
	return m_len;
}

template <std::size_t N>
inline
bool
CappedString<N>::empty() const
{
	return m_len == 0;
}

template <std::size_t N>
inline
bool
CappedString<N>::is_truncated() const
{
	return m_is_truncated;
}

template <std::size_t N>
inline
void
CappedString<N>::clear()
{
	m_data[0] = '\0';
	m_len = 0;
	return;
}

template <std::size_t N>
void
CappedString<N>::initialize_from_c_string(char const* p_string)
{
	m_is_truncated = false;
	m_len = 0;
	while ((m_data[m_len] = p_string[m_len]) != '\0')
	{
		if (m_len == N)
		{
			m_is_truncated = true;
			m_data[m_len] = '\0';
			return;
		}
		++m_len;
	}
	return;
}

template <std::size_t N>
void
CappedString<N>::unchecked_assign(CappedString const& rhs)
{
	m_is_truncated = rhs.m_is_truncated;
	m_len = rhs.m_len;

	// With compiler optimization, this appears to be as fast as memcpy,
	// is also safer in case we ever allow non-POD char types.
	std::copy(rhs.m_data, rhs.m_data + m_len + 1, m_data);

	return;
}

/**
 * Write to an output stream.
 */
template <typename traits, std::size_t N>
std::basic_ostream<typename CappedString<N>::value_type, traits>&
operator<<
(	std::basic_ostream<typename CappedString<N>::value_type, traits>& os,
	CappedString<N> const& str
)
{
	return os << str.c_str();
}



}  // namespace jewel

#endif   // GUARD_capped_string_hpp
