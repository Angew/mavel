#pragma once

#include "mavel/detail/operation_set_selector.hpp"


namespace mvl {

template <class Component>
struct operation_set_selector : detail::operation_set_selector<Component>
{};

}	//namespace mvl
