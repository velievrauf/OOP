cmake_minimum_required(VERSION 3.26)

add_library(game INTERFACE)

target_sources(
	game
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/custom_memory_resource.h
	${CMAKE_CURRENT_SOURCE_DIR}/my_struct.h
	${CMAKE_CURRENT_SOURCE_DIR}/pmr_list.h
	${CMAKE_CURRENT_SOURCE_DIR}/custom_memory_resource.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/my_struct.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/pmr_list.cpp
)

target_include_directories(
	game
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)
