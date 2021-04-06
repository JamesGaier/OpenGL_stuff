cmake_minimum_required(VERSION 3.20)
project(Platformer)

add_executable(learn src/learn.cpp)

target_link_libraries(
	learn 
	PRIVATE 
	glad
	glfw)

add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(tests)

