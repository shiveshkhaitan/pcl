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

set(INCLUDE_FILES "")
foreach(module ${SUBSYS_DEPS})
  execute_process (COMMAND grep -rh "#include <pcl" ${PCL_SOURCE_DIR}/${module}/ OUTPUT_FILE  ${CMAKE_CURRENT_LIST_DIR}/all_cmake_includes.hpp )
  file(GLOB_RECURSE includes RELATIVE
    "${PCL_SOURCE_DIR}/${module}/include/*.hpp"
    "${PCL_SOURCE_DIR}/${module}/include/*.h"
  )

  foreach(file ${includes})
    string(REGEX REPLACE "\\.\\.\\/" "" file ${file})
    if (NOT ${file} MATCHES ".pcl_tests.")
      file (APPEND ${CMAKE_CURRENT_LIST_DIR}/all_cmake_includes.hpp "#include <${file}>\n")
    endif()
  endforeach()
endforeach()

execute_process (COMMAND
  /usr/local/bin/binder --root-module pcl_python --prefix ${CMAKE_CURRENT_LIST_DIR}/ --bind "" ${CMAKE_CURRENT_LIST_DIR}/all_cmake_includes.hpp -- -std=c++14 -I ${PCL_SOURCE_DIR}/build/include -I ${PCL_SOURCE_DIR}/common/include -I ${EIGEN_INCLUDE_DIRS} -DNDEBUG
)

find_package(pybind11 REQUIRED)
find_package(Binder REQUIRED)
include_directories(${pybind11_INCLUDE_DIRS})
include_directories(${BINDER_INCLUDE_DIR})

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
