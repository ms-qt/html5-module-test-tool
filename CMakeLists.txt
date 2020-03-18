cmake_minimum_required(VERSION 3.5)

project(html5-module-test-tool LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick WebEngine WebChannel REQUIRED)


add_executable(html5-module-test-tool
        main.cpp
        bdlbsc/module/web/WebDataComponent.cpp
        bdlbsc/module/web/WebDataComponent.h
        qml.qrc
        )

target_compile_definitions(html5-module-test-tool
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(html5-module-test-tool
        PRIVATE Qt5::Core Qt5::Quick Qt5::WebEngine Qt5::WebChannel)
