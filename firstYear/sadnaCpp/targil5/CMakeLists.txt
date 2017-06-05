cmake_minimum_required(VERSION 2.8)

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB sub-dir RELATIVE ${curdir} *)
foreach(dir ${sub-dir})
	if(IS_DIRECTORY ${curdir}/${dir} AND NOT (${dir} STREQUAL ".git" OR ${dir} STREQUAL "CMakeFiles" OR ${dir} STREQUAL "q2"))
		ADD_SUBDIRECTORY(${dir})
	endif()
endforeach()

