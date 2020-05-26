cmake_minimum_required(VERSION 3.16)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. APP_SOURCES)
#add_library( YourLib ${LIB_SOURCES} ${LIB_HEADERS} )
foreach (source_file ${APP_SOURCES})
    # cut off .cpp.
    # string(REPLACE <match_string>
    #       <replace_string> <output variable>
    #       <input> [<input>...])
    string(REPLACE ".cpp" "" exec_name ${source_file})
    # replace non-acceptable character
    STRING(REGEX REPLACE "[^0-9a-zA-Z]" "" exec_name ${exec_name})
    # cut off "./"
    # string(SUBSTRING <string> <begin> <length> <output variable>)
    # string(SUBSTRING ${exec_name} 2 -1 exec_name)

    add_executable(${exec_name} ${source_file} LeetCodeLib.h)
    # Make sure YourLib is linked to each app
    #    target_link_libraries( ${exec_name} YourLib )
endforeach (source_file ${APP_SOURCES})
