#cmake file for project association
#author:>---LDE Team
#created:>--2015/08/29

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)                  
                                                        

PROJECT(src)                                 

MESSAGE(STATUS "Project: src")                       
MESSAGE(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(Qt5Xml)
find_package(Qt5WebKitWidgets)
find_package(Qt5DBus)
find_package(PythonLibs 2)

include_directories(${PYTHON_INCLUDE_DIRS})

qt5_wrap_ui(UIS_HDRS player.ui playlist.ui transformer.ui sortingdialog.ui settingsdialog.ui reslibrary.ui detailview.ui cutterbar.ui detailitem.ui)

qt5_add_resources(QRCS_CPPS rc.qrc)

# Tell CMake to create the helloworld executable
add_executable(lplayer main.cpp player.cpp mplayer.cpp playlist.cpp webvideo.cpp skin.cpp httpget.cpp downloader.cpp plugins.cpp pyapi.cpp transformer.cpp sortingdialog.cpp settingsdialog.cpp reslibrary.cpp resplugin.cpp mybuttongroup.cpp detailview.cpp utils.cpp mylistwidget.cpp cutterbar.cpp videocombiner.cpp searcher.cpp acfun.cpp youget.cpp detailitem.cpp detailpage.cpp laboutwidget.cpp ${UIS_HDRS} ${QRCS_CPPS})

# Use the Widgets module from Qt 5.
target_link_libraries(lplayer Qt5::Widgets Qt5::Network Qt5::Xml Qt5::WebKitWidgets Qt5::DBus ${PYTHON_LIBRARIES})

INSTALL(DIRECTORY skins DESTINATION /usr/share/lplayer)
INSTALL(FILES lplayer_zh_CN.qm DESTINATION /usr/share/lplayer)
INSTALL(FILES images/lplayer.png DESTINATION /usr/share/Icons)
INSTALL(TARGETS lplayer RUNTIME DESTINATION /usr/bin)
INSTALL(DIRECTORY plugins DESTINATION /usr/share/lplayer)
INSTALL(FILES lplayer.desktop DESTINATION /usr/share/application)
                           
