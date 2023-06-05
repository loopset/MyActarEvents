#-----MyActarEvents-----

# Setup the project
cmake_minimum_required(VERSION 3.20 FATAL_ERROR) #need to look at this
project(MyActarEvents)

# stablish c++ version
set(CMAKE_CXX_STANDARD 17) # same as ROOT built for Arch Linux
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(ROOT 6.20 CONFIG REQUIRED)

# ActRoot and ROOT inc directories
include_directories(${ROOT_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/inc)

file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.h)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)

# ActRoot LinkDef and dict generation
set(LINKDEF_LOCATION ${PROJECT_SOURCE_DIR}/MyActarEventsLinkDef.h )
set(DICTIONARY_NAME G__${PROJECT_NAME})

ROOT_GENERATE_DICTIONARY(${DICTIONARY_NAME} ${headers} LINKDEF  ${LINKDEF_LOCATION})

# and add library
set(TARGET_NAME ${PROJECT_NAME})
add_library(${TARGET_NAME} SHARED ${sources} ${headers} ${DICTIONARY_NAME}.cxx)
# link against ROOT libraries
target_link_libraries(${TARGET_NAME} ${ROOT_LIBRARIES})
