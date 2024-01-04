cmake_minimum_required(VERSION 3.14)

project(untitled11 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH /Users/zijianyang/Qt/5.15.0/clang_64)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/usr/local/include)

include_directories(./net)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

if (ANDROID)
    add_library(untitled11 SHARED
            main.cpp
            qml.qrc
            )
else ()
    add_executable(untitled11
            main.cpp
            qml.qrc
            backend.cpp
            backend.h
            net/TcpServer.cpp net/TcpServer.h net/TcpConnection.cpp net/TcpConnection.h data/global.cpp data/global.h)
endif ()

target_compile_definitions(untitled11
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(untitled11
        PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
