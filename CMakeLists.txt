cmake_minimum_required(VERSION 3.3)

project(MaVeL)

set(MaVeL_DEVELOP FALSE CACHE BOOL "Generate targets for developing MaVeL, as opposed to only installing & using it")
set(MaVeL_TEST FALSE CACHE BOOL "Generate tests for MaVeL")

find_package(Boost REQUIRED)

add_library(MaVeL INTERFACE)
target_include_directories(MaVeL INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${Boost_INCLUDE_DIRS}
)
# set_property(
	# TARGET MaVeL
	# PROPERTY INTERFACE_INCLUDE_DIRECTORIES
# )

if(MaVeL_DEVELOP)
	add_library(MaVeL_dev STATIC
		include/mavel/component_underlying_type.hpp
		include/mavel/operation_set.hpp
		include/mavel/operation_set_selector.hpp
		include/mavel/simd_iffast.hpp
		include/mavel/simd_type_selector.hpp
		include/mavel/vector.hpp

		include/mavel/detail/component_underlying_type.hpp
		include/mavel/detail/operation_set_selector.hpp
		include/mavel/detail/simd_type_selector.hpp
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

if(MaVeL_TEST)
	enable_testing()
	add_library(MaVeL_test_static_default STATIC
		EXCLUDE_FROM_ALL
		test/static/default.cpp
	)
	target_link_libraries(MaVeL_test_static_default MaVeL)
	add_test(
		NAME MaVeL_test_static_default
		COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target MaVeL_test_static_default --config $<CONFIG> --clean-first
	)
endif()
