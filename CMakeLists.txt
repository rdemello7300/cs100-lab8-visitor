CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(iteratorTest
   test.cpp
   iterator.cpp
)

ADD_EXECUTABLE(latexTest
    test.cpp
    iterator.cpp
)

TARGET_LINK_LIBRARIES(iteratorTest gtest)
TARGET_LINK_LIBRARIES(latexTest gtest)
TARGET_COMPILE_DEFINITIONS(iteratorTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(latexTest PRIVATE gtest_disable_pthreads=ON)
