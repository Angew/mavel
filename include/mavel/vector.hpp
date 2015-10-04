#pragma once

#include <cstddef>


namespace mvl {

template <
	class Component,
	::std::size_t Dimension,
	operation_set OperationSet = operation_set_selector<Component>::value,
	class SimdUsage = iffast_simd_t<OperationSet>
>
class vector;

}	//namespace mvl
