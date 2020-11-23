
project(learn-cpp)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG )
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Hellocpp Hellocpp.cpp )
add_executable(helloworld hello/HelloWorld.cpp)
add_executable(TypeTest type/TypeTest.cpp )
add_executable(structTest type/StructTest.cpp type/Person.h type/Uu.cpp type/Color.h)
add_executable(pointerTest type/Pointer.cpp)
add_executable(ArrayTest type/ArrayTest.cpp clib/CCTypeTest.cpp)
add_executable(ReferenceTest type/ReferenceTest.cpp)

add_executable(MemCommitTest sys/MemCommitTest.cpp)
add_executable(ThreadScheduleTest sys/ThreadScheduleTest.cpp)

add_executable(FunctionTest sys/FunctionTest.cpp)

add_executable(Jill namespace/Jill.cpp)

add_executable(Stock oop/Stock.h oop/Stock.cpp oop/Invoker.cpp oop/OpStock.cpp)

add_executable(externTest type/extern/Main.cpp type/extern/Support.cpp)
