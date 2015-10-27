#pragma once

#include "mavel/component_underlying_type.hpp"
#include "mavel/operation_set_selector.hpp"
#include "mavel/simd_iffast.hpp"
#include "mavel/simd_type_selector.hpp"

#include <cstddef>


namespace mvl {

template <
	class Component,
	::std::size_t Dimension,
	operation_set OperationSet = operation_set_selector<component_underlying_type_t<Component>>::value,
	class SimdUsage = simd_iffast,
	class SimdType = simd_type_selector_t<component_underlying_type_t<Component>, OperationSet>
>
class vector
{};

}	//namespace mvl
