CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(iteratorTest
   operandTest.cpp
   iterator.cpp
)

ADD_EXECUTABLE(latexTest
    latexTest.cpp
    iterator.cpp
)

ADD_EXECUTABLE(mathMLTest
    MathmlTest.cpp
    iterator.cpp
)

TARGET_LINK_LIBRARIES(iteratorTest gtest)
TARGET_LINK_LIBRARIES(latexTest gtest)
TARGET_LINK_LIBRARIES(mathMLTest gtest)
TARGET_COMPILE_DEFINITIONS(iteratorTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(latexTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(mathMLTest PRIVATE gtest_disable_pthreads=ON)
