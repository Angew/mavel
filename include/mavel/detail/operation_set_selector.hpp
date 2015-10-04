#pragma once

#include "mavel/operation_set.hpp"

#include <type_traits>


namespace mvl {

namespace detail {

template <
	class Component,
	bool IsIntegral = ::std::is_integral<Component>::value
>
struct operation_set_selector;
//--------------------------------------------------------------------------------------------------
template <class Component>
struct operation_set_selector<Component, false>
{
	static constexpr operation_set value = operation_set::real;
};
//--------------------------------------------------------------------------------------------------
template <class Component>
struct operation_set_selector<Component, true>
{
	static constexpr operation_set value = operation_set::integral;
};

}	//namespace detail

}	//namespace mvl
