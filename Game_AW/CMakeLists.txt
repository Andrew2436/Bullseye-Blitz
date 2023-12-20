set(HEADER_FILES 
	MyGame.h
)

set(SOURCE_FILES
	main.cpp
	MyGame.cpp
)



add_executable(Game_AW ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_AW Otter)

include_directories(../Otter/include)