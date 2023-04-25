cmake_minimum_required(VERSION 3.24)

project(QTo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_32")

include_directories(./)


include(../lib/poppler/import_poppler.cmake)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB_RECURSE UI_FILE *.h *.cpp *.ui)
file(GLOB_RECURSE RESOURCE_FILE *.qrc *.rc)
file(GLOB_RECURSE COMMON_FILE *.h *.cpp)

add_executable(QTo main.cpp ${RESOURCE_FILE} ${UI_FILE} ${COMMON_FILE})

target_link_libraries(QTo
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Xml)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

#屏蔽控制台
set(CMAKE_CXX_FLAGS_RELEASE "-mwindows")