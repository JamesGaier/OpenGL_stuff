cmake_minimum_required(VERSION 3.20)
project(Platformer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(learn src/learn.cpp)
add_executable(shaders src/shaders.cpp)
add_executable(uniforms src/uniforms.cpp)
add_executable(more_colors src/more_colors.cpp)
add_executable(
		shader_abs 
		src/shader_abs.cpp
		include/shader.h
)
add_executable(textures src/textures.cpp)

target_link_libraries(
	learn 
	PRIVATE 
	glad
	glfw
	glm
)

target_link_libraries(
	shaders 
	PRIVATE 
	glad
	glfw
	glm
)

target_link_libraries(
	uniforms 
	PRIVATE 
	glad
	glfw
)

target_link_libraries(
	more_colors 
	PRIVATE 
	glad
	glfw
	glm
)

target_link_libraries(
	shader_abs
	PRIVATE 
	glad
	glfw
	glm
)

target_link_libraries(
	textures
	PRIVATE
	glad
	glfw
	glm
	stb_image
)

add_subdirectory(external)
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
