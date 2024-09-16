cmake_minimum_required(VERSION 3.5)

project(QTradingView VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Network WebEngineWidgets)
find_package(Qt6WebSockets REQUIRED)
find_package(Qt6Sql REQUIRED)
# set(QSCINTILLA_INCLUDE_DIR "/usr/include/x86_64-linux-gnu/Qsci/")
set(SQL_INCLUDE_DIR "/usr/include/x86_64-linux-gnu/qt6/QtSql/")
set(QSCINTILLA_LIBRARY "${CMAKE_CURRENT_LIST_DIR}/lib/QScintilla/src/libqscintilla2_qt6.so.15.2")
# set(MYSQL_DRIVER "${CMAKE_CURRENT_LIST_DIR}/plugins/sqldrivers/libmysqlclient.so")
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h 
        axes.h
        axes.cpp
        graphTimeFrameNode.h
        graphTimeFrameNode.cpp
        candleBody.h
        candleBody.cpp
        candleStickState.h
        candleStickState.cpp
        pathGraphPoint.h
        pathGraphPoint.cpp
        candleStickWick.cpp 
        candleStickWick.h
        candleStickDataStream.h 
        candleStickDataStream.cpp
        graph.h 
        graph.cpp 
        dbManager.cpp 
        dbManager.h 
        GraphingView.cpp 
        GraphingView.h
        graphWindow.h 
        graphWindow.cpp 
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTradingView
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QTradingView APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QTradingView SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QTradingView
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_directories(QTradingView PRIVATE ${QSCINTILLA_INCLUDE_DIR})
# target_link_directories(QTradingView PRIVATE ${SQL_INCLUDE_DIR})

target_link_libraries(QTradingView PRIVATE Qt6WebSockets)
target_link_libraries(QTradingView PRIVATE Qt6Sql)
target_link_libraries(QTradingView PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSN_MAJOR}::Core Qt6::Network Qt6::WebEngineWidgets)
target_link_libraries(QTradingView PRIVATE ${QSCINTILLA_LIBRARY})
# target_link_libraries(QTradingView PRIVATE ${MYSQL_DRIVER})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTradingView)
endif()
set_target_properties(QTradingView PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QTradingView
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTradingView)
endif()
