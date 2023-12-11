set(HEADER_FILES 
	include/Otter.h
	OtterApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DOT_DEBUG=2)
add_definitions(-DOTTER_LIB)

include_directories(../Otter)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Otter SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Otter PRIVATE pch.h)

target_link_libraries(Otter glfw)
target_link_libraries(Otter glad)
target_link_libraries(Otter stbi)


