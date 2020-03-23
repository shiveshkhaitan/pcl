set(SUBSYS_NAME python)
set(SUBSYS_DESC "Point cloud python bindings")
set(SUBSYS_DEPS common)

set(build TRUE)
PCL_SUBSYS_OPTION(build "${SUBSYS_NAME}" "${SUBSYS_DESC}" ON)
PCL_SUBSYS_DEPEND(build "${SUBSYS_NAME}" DEPS ${SUBSYS_DEPS} EXT_DEPS eigen boost)

PCL_ADD_DOC("${SUBSYS_NAME}")

if(NOT build)
  return()
endif()

execute_process (COMMAND
	/usr/local/bin/binder --root-module pcl_python --prefix ${CMAKE_CURRENT_LIST_DIR}/ --bind "" --config ${CMAKE_CURRENT_LIST_DIR}/pcl.config ${CMAKE_CURRENT_LIST_DIR}/all_cmake_includes.hpp -- -std=c++14 -I ${CMAKE_CURRENT_LIST_DIR}/include -I ${PCL_SOURCE_DIR}/build/include -I ${PCL_SOURCE_DIR}/common/include -I ${EIGEN_INCLUDE_DIRS} -DNDEBUG
)

find_package(pybind11 REQUIRED)
include_directories(${pybind11_INCLUDE_DIRS})

set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)
add_definitions(-DNDEBUG)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_LIST_DIR}/
    "*.cpp"
)

set(LIB_NAME "pcl_${SUBSYS_NAME}")
PCL_ADD_LIBRARY(${LIB_NAME} COMPONENT ${SUBSYS_NAME} SOURCES ${SRC})

target_link_libraries(${LIB_NAME} pcl_common)
set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX ".so")
