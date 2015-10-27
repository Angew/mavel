#pragma once


namespace mvl {

namespace detail {

template <class Component>
struct component_underlying_type
{
	using type = Component;
};

}	//namespace detail

}	//namespace mvl
