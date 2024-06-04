cmake_minimum_required(VERSION 3.26)
project(Proj10)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj10
        proj10-ContainerIfc.h
        proj10-Node.h
        proj10-MyList.h
        proj10-MyVector.h
        proj10-Queue1.h
        proj10-Queue2.h
        proj10-Queue3.h
        proj10-driver.cpp)
