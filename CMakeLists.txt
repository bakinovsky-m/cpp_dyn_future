project(cpp_dyn_future)

add_executable(exe main.cpp)
target_link_libraries(exe ${CMAKE_DL_LIBS})

add_library(lib SHARED lib.cpp)
find_package(Threads REQUIRED)
target_link_libraries(lib Threads::Threads)
