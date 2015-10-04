#pragma once

#include "mavel/detail/simd_type_selector.hpp"

#include "mavel/operation_set.hpp"

#include <boost/mpl/contains.hpp>
#include <boost/mpl/vector.hpp>

#include <cstdint>
#include <type_traits>


namespace mvl {

namespace detail {

using simd_types = ::boost::mpl::vector<
	float,
	double,
	::std::int32_t,
	::std::uint32_t,
	::std::int16_t,
	::std::uint16_t,
	::std::int8_t,
	::std::uint8_t
>;
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
template <class T>
struct is_simd_type : ::boost::mpl::contains<simd_types, T>
{};
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
template <class Type, operation_set OperationSet>
struct check_type_operation_compatibility
{
	static_assert(
		::std::is_floating_point<Type>::value == (OperationSet == operation_set::real),
		"Mismatch between underlying SIMD type and operation set"
	);
	using type = Type;
};
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
template <
	class Component,
	operation_set OperationSet,
	bool IsSimdType = is_simd_type<Component>::value
>
struct simd_type_selector;
//--------------------------------------------------------------------------------------------------
template <
	class Component,
	operation_set OperationSet
>
struct simd_type_selector<Component, OperationSet, true>
{
	using type = typename check_type_operation_compatibility<Component, OperationSet>::type;
};
//--------------------------------------------------------------------------------------------------
template <
	class Component,
	operation_set OperationSet
>
class simd_type_selector<Component, OperationSet, false>
{
	using iter = typename ::boost::mpl::find_if<
		simd_types,
		::boost::mpl::and_<
			::boost::mpl::equal_to<
				::boost::mpl::sizeof_<::boost::mpl::_1>,
				::boost::mpl::sizeof_<Component>
			>,

		>,
	using type = ;
};
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
template <
	class Component,
	operation_set OperationSet
>
using simd_type_selector_t = typename simd_type_selector<Component, OperationSet>::type;

}	//namespace detail

}	//namespace mvl
