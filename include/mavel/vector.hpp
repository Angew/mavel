#pragma once

#include "mavel/operation_set_selector.hpp"
#include "mavel/simd_iffast.hpp"
#include "mavel/simd_type_selector.hpp"

#include <cstddef>


namespace mvl {

template <
	class Component,
	::std::size_t Dimension,
	operation_set OperationSet = operation_set_selector<Component>::value,
	class SimdUsage = iffast_simd_t<simd_type_selector_t<Component, OperationSet>>
>
class vector;

}	//namespace mvl
