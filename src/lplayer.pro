#-------------------------------------------------
#
# Project created by QtCreator 2012-09-08T16:18:28
#
#-------------------------------------------------

QT       += core gui network xml webkitwidgets
unix: QT += dbus
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = lplayer
TEMPLATE = app


SOURCES += main.cpp\
        player.cpp \
    mplayer.cpp \
    playlist.cpp \
    webvideo.cpp \
    skin.cpp \
    httpget.cpp \
    downloader.cpp \
    plugins.cpp \
    pyapi.cpp \
    transformer.cpp \
    sortingdialog.cpp \
    settingsdialog.cpp \
    reslibrary.cpp \
    resplugin.cpp \
    mybuttongroup.cpp \
    detailview.cpp \
    utils.cpp \
    mylistwidget.cpp \
    cutterbar.cpp \
    videocombiner.cpp \
    searcher.cpp \
    acfun.cpp \
    youget.cpp \
    detailitem.cpp \
    detailpage.cpp \
    laboutwidget.cpp


TRANSLATIONS += lplayer_zh_CN.ts


HEADERS  += player.h \
    mplayer.h \
    playlist.h \
    webvideo.h \
    skin.h \
    httpget.h \
    downloader.h \
    plugins.h \
    pyapi.h \
    transformer.h \
    sortingdialog.h \
    settings_player.h \
    settings_video.h \
    settings_network.h \
    settingsdialog.h \
    reslibrary.h \
    resplugin.h \
    accessmanager.h \
    mybuttongroup.h \
    detailview.h \
    utils.h \
    mylistwidget.h \
    settings_audio.h \
    cutterbar.h \
    settings_plugins.h \
    videocombiner.h \
    searcher.h \
    acfun.h \
    youget.h \
    detailitem.h \
    detailpage.h \
    laboutwidget.h


FORMS    += \
    player.ui \
    playlist.ui \
    transformer.ui \
    sortingdialog.ui \
    settingsdialog.ui \
    reslibrary.ui \
    detailview.ui \
    cutterbar.ui \
    detailitem.ui


unix {
    #skin
    default_skin.files += skins
    default_skin.path = /usr/share/lplayer
    #translation
    trans.files += lplayer_*.qm
    trans.path = /usr/share/lplayer
    #icon
    icon.files += lplayer.svg
    icon.path = /usr/share/icons
    #bin
    execute.files += lplayer
    execute.path = /usr/bin
    #plugins
    plugin.files += plugins
    plugin.path = /usr/share/lplayer
    #menu
    menu.files += lplayer.desktop
    menu.path = /usr/share/applications
    INSTALLS += default_skin execute trans icon menu plugin
}

RC_FILE = icon.rc

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += python2

win32: INCLUDEPATH += C:\\Python27\\include
win32: LIBS += C:\\Python27\\libs\\python27.lib

RESOURCES += \
    rc.qrc
