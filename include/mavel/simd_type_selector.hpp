#pragma once

#include "mavel/detail/simd_type_selector.hpp"

#include "mavel/operation_set.hpp"


namespace mvl {

template <
	class Component,
	operation_set OperationSet
>
struct simd_type_selector : detail::simd_type_selector<Component, OperationSet>
{};
//--------------------------------------------------------------------------------------------------
template <
	class Component,
		operation_set OperationSet
>
using simd_type_selector_t = typename simd_type_selector<Component, OperationSet>::type;

}	//namespace mvl
