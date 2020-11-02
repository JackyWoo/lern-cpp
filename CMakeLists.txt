cmake_minimum_required(VERSION 3.16)
project(learn-cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hellocpp Hellocpp.cpp )
add_executable(helloworld hello/HelloWorld.cpp)
add_executable(TypeTest type/TypeTest.cpp )
add_executable(structTest type/StructTest.cpp type/Person.h type/Uu.cpp type/Color.h )
add_executable(pointerTest type/Pointer.cpp)