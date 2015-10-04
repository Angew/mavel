cmake_minimum_required(VERSION 3.3)

project(MaVeL)

set(MaVeL_DEVELOP FALSE CACHE BOOL "Generate targets for developing MaVeL, as opposed to only installing & using it")

find_package(Boost REQUIRED)

add_library(MaVeL INTERFACE)
set_property(
	TARGET MaVeL
	PROPERTY INTERFACE_INCLUDE_DIRECTORIES
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MaVeL_DEVELOP)
	add_library(MaVeL_dev STATIC
		include/mavel/operation_set.hpp
		include/mavel/operation_set_selector.hpp
		include/mavel/simd_iffast.hpp
		include/mavel/simd_type_selector.hpp
		include/mavel/vector.hpp

		include/mavel/detail/operation_set_selector.hpp
	)
	set_target_properties(
		MaVeL_dev
		PROPERTIES
		LINKER_LANGUAGE CXX
		OUTPUT_NAME mavel
	)
	target_link_libraries(MaVeL_dev PUBLIC MaVeL)
	source_group("Header Files\\detail" REGULAR_EXPRESSION include/mavel/detail/*)
endif()
