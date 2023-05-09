cmake_minimum_required(VERSION 3.5)

project(grille-crypt-qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(UNIX)
        set(SystemDepended grille-crypt/src/LinuxRandomStream.cpp grille-crypt/src/LinuxFactory.h grille-crypt/src/LinuxFactory.cpp grille-crypt/src/LinuxFactoryBuilder.cpp)
        message(STATUS "Build for unix")
else()
    message(STATUS "Build not for unix")
endif()

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        actionwindow.h
        actionwindow.cpp
        actiontypes.h
        grille-crypt/src/GrilleKey.h grille-crypt/src/GrilleKey.cpp grille-crypt/src/AbstractCryptStream.h grille-crypt/src/AbstractCryptStream.cpp grille-crypt/src/EncryptStream.h grille-crypt/src/EncryptStream.cpp grille-crypt/src/AbstractRandomStream.h grille-crypt/src/LinuxRandomStream.h grille-crypt/src/AbstractSystemDependedFactory.h grille-crypt/src/AbstractSystemDependedFactory.cpp grille-crypt/src/DecryptStream.h grille-crypt/src/DecryptStream.cpp grille-crypt/src/KeyGenerator.h grille-crypt/src/KeyGenerator.cpp grille-crypt/src/XorCrypt.h grille-crypt/src/XorCrypt.cpp grille-crypt/src/converter.h grille-crypt/src/converter.cpp grille-crypt/src/FileFormatter.h grille-crypt/src/FileFormatter.cpp grille-crypt/src/FileValidator.h grille-crypt/src/FileValidator.cpp grille-crypt/src/GrilleCrypt.h grille-crypt/src/GrilleCrypt.cpp grille-crypt/src/Cli.h grille-crypt/src/Cli.cpp ${SystemDepended}
)

add_subdirectory(grille-crypt/)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(grille-crypt-qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET grille-crypt-qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(grille-crypt-qt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(grille-crypt-qt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(grille-crypt-qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(grille-crypt-qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS grille-crypt-qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(grille-crypt-qt)
endif()
