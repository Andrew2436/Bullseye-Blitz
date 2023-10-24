set(HEADER_FILES 
	include/Otter.h
	OtterApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DOT_DEBUG=2)
add_definitions(-DOTTER_LIB)

if(WIN32)
	add_definitions(-DOTTER_MSCPP)
elseif(LINUX)
	add_definitions(-DOTTER_LINUX)
elseif(APPLE)
	add_definitions(-DOTTER_APPLE)
endif()

add_library(Otter SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Otter PRIVATE pch.h)