
SET(PROJECT_NAME "JKCpp11Mutex")

ADD_DEFINITIONS(-D_JK_BUILD_DLL)

FILE(GLOB source_file_list *.cpp)
FILE(GLOB header_file_list *.h)
	
SET(src_list 
	${source_file_list}
	${header_file_list}
)

#ADD_LIBRARY(${PROJECT_NAME} SHARED ${src_list})
#INCLUDE_DIRECTORIES( ./ )
#ADD_LIBRARY(${PROJECT_NAME} ${BUILD_DYNAMIC_OR_STATIC} ${src_list})
ADD_EXECUTABLE(${PROJECT_NAME} ${src_list})

IF(WIN32)
#	TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
#		debug glfw3.lib optimized glfw3.lib
#	)
ENDIF(WIN32)
if(UNIX)
#	TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
#		debug glfw3.so optimized glfw3.so
#	)
ENDIF(UNIX)