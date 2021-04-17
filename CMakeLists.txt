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
add_executable(math src/math.cpp)
add_executable(perspective src/perspective.cpp)
add_executable(rotating_cube src/rotating_cube.cpp)
add_executable(
		look_around 
		src/look_around.cpp
		include/utils.h
)
add_executable(
		camera_controller 
		src/camera_controller.cpp
		include/utils.h
		include/camera.h
)

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

target_link_libraries(
	math 
	PRIVATE 
	glad
	glfw
	glm
	stb_image
)

target_link_libraries(
	perspective 
	PRIVATE 
	glad
	glfw
	glm
	stb_image
)


target_link_libraries(
	rotating_cube 
	PRIVATE 
	glad
	glfw
	glm
	stb_image
)

target_link_libraries(
	look_around 
	PRIVATE 
	glad
	glfw
	glm
	stb_image
)

target_link_libraries(
	camera_controller 
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
