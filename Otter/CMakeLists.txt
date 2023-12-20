set(HEADER_FILES 
	include/Otter.h
	OtterApp.h
	Events.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Utilities.h
	WindowImplementation.h
)

set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
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


