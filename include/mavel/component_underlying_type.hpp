#pragma once

#include "mavel/detail/component_underlying_type.hpp"


namespace mvl {

template <class Component>
struct component_underlying_type : detail::component_underlying_type<Component>
{};
//--------------------------------------------------------------------------------------------------
template <class Component>
using component_underlying_type_t = typename component_underlying_type<Component>::type;

}	//namespace mvl
