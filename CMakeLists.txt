cmake_minimum_required(VERSION 3.16)

project(learn-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG )
set(CMAKE_CXX_FLAGS -pthread)



add_executable(test Test.cpp)

add_executable(Hellocpp Hellocpp.cpp )
add_executable(helloworld hello/HelloWorld.cpp)


# --------------  type --------------
add_executable(TypeTest type/TypeTest.cpp )
add_executable(structTest type/StructTest.cpp type/Person.h type/Uu.cpp type/Color.h)
add_executable(pointerTest type/Pointer.cpp)
add_executable(ArrayTest type/ArrayTest.cpp clib/CCTypeTest.cpp)
add_executable(ReferenceTest type/ReferenceTest.cpp)
add_executable(StringTest type/StringTest.cpp)

add_executable(MemCommitTest sys/MemCommitTest.cpp)
add_executable(ThreadScheduleTest sys/ThreadScheduleTest.cpp)

add_executable(FunctionTest sys/FunctionTest.cpp)

add_executable(Jill namespace/Jill.cpp)
add_executable(externTest type/extern/Main.cpp type/extern/Support.cpp)

# --------------  constructor --------------

add_executable(ConstructorTest oop/Stock.h oop/Stock.cpp constructor/ConstructorTest.cpp)
add_executable(ConstructorTest2 constructor/ConstructorTest2.cpp)
add_executable(NewTest operator/NewTest.cpp)


# --------------  oop --------------

add_executable(Stock oop/Stock.h oop/Stock.cpp oop/Invoker.cpp oop/OpStock.cpp)
add_executable(MethodOverrideTest oop/MethodOverrideTest.cpp )
add_executable(ConstructorOverrideTest oop/ConstructorOverrideTest.cpp )
add_executable(PolyTest oop/PolyTest.cpp )
add_executable(PeopleTest oop/PeopleTest.cpp oop/People.cpp oop/Man.cpp)


# --------------  STL --------------

add_executable(StringTest1 stl/StringTest.cpp)
add_executable(VectorTest stl/VectorTest.cpp)
add_executable(MapTest stl/MapTest.cpp)
add_executable(UnorderdMapTest stl/UnorderdMapTest.cpp)
add_executable(ListTest stl/ListTest.cpp)
add_executable(SetTest stl/SetTest.cpp)


# --------------  Template --------------



#--------------  queue --------------

add_executable(BlockingQueueTest   queue/BlockingQueueTest.cpp)
add_executable(ThreadPoolTest queue/FixedThreadPool.cpp queue/FixedThreadPoolTest.cpp)

#--------------  x_ptr --------------

add_executable(ResourceReleaseTest x_ptr/ResourceReleaseTest.cpp  oop/Stock.h  oop/Stock.cpp)


add_executable(UniquePtrTest x_ptr/UniquePtrTest.cpp)
add_executable(SharedPtrTest x_ptr/SharedPtrTest.cpp)
add_executable(NullPtrTest x_ptr/NullPtrTest.cpp)

#--------------  pointer --------------



#--------------  ref --------------

add_executable(RefTest ref/RefTest.cpp)
add_executable(RefTest2 ref/RefTest2.cpp)

#--------------  thread --------------

add_executable(ThreadTest thread/ThreadTest.cpp)

#--------------  cpp11 --------------

add_executable(BackReturnTypeTest cpp11/BackReturnTypeTest.cpp)
add_executable(DefaultTemplateArgName cpp11/DefaultTemplateArgName.cpp)
add_executable(InitObjectTest cpp11/InitObjectTest.cpp)
add_executable(MoveConstructorTest cpp11/MoveConstructorTest.cpp)
add_executable(ArgDeliverTest cpp11/PerfectForwarding.cpp)


#--------------  operator --------------

add_executable(OperatorOverrideTest operator/OperatorOverrideTest.cpp)
add_executable(OperatorOverrideTest1 operator/OperatorOverrideTest1.cpp)

#--------------  template --------------

add_executable(ArrayTemplateTest template/ArrayTemplateTest.cpp)
add_executable(FooTest template/FooTest.cpp template/Foo.cpp)


#--------------  exception --------------

add_executable(ExceptionTest exception/ExceptionTest.cpp)


#--------------  exception --------------

add_executable(DynamicCastTest cast/DynamicCastTest.cpp)


#--------------  ThreadPoolTest --------------

add_executable(ThreadPoolTest2 threadpool/KeyedThreadPoolTest.cpp threadpool/KeyedThreadPool.cpp threadpool/getNumberOfPhysicalCPUCores.cpp)

#--------------  time --------------

add_executable(ChronoTest time/ChronoTest.cpp)


