cmake_minimum_required(VERSION 2.8.3)
project(hydrophones)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS

  qt_build
  roscpp
  roslib
  std_msgs
)

find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui)
include(${QT_USE_FILE})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
set(QT_MOC include/hydrophones/hydrophones.h include/hydrophones/qcustomplot.h)
SET(QT_SOURCES src/hydrophones.cpp src/qcustomplot.cpp)

################################################
## Setup QT
################################################
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})


###################################
## catkin specific configuration ##
###################################
catkin_package()
include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
	${QT_INCLUDE_DIRS}
)

add_library(hydrophones_lib ${QT_SOURCES} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(hydrophones_lib ${QT_LIBRARIES} ${catkin_LIBRARIES} )

add_executable(hydrophones src/main.cpp)
target_link_libraries(hydrophones hydrophones_lib)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
