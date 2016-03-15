#pragma once

#include "mavel/operation_set.hpp"
#include "mavel/operation_set_selector.hpp"

#include <cstddef>


namespace mvl {

template <
	class Component,
	::std::size_t Dimension,
	operation_set OperationSet = operation_set_selector<Component>::value,
>
class vector;

}	//namespace mvl
