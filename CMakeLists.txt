cmake_minimum_required(VERSION 3.16)

project(BoardGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)


# Add the Qt resource file
# qt_add_resources(RESOURCE_FILES resources.qrc)

qt_add_executable(appBoardGame
    main.cpp
)

qt_add_qml_module(appBoardGame
    URI BoardGame
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES mainwindow.qml
        SOURCES BoardGame_Classes.h
        SOURCES TicTacToe5x5.h
        QML_FILES TicTacToe5x5.qml
        RESOURCES resources.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appBoardGame PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appBoardGame
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appBoardGame
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appBoardGame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
