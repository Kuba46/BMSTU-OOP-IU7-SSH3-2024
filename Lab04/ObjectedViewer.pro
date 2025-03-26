QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logic/file_readers/basefilereader.cpp \
    logic/scene/figure/components/edge.cpp \
    logic/facade.cpp \
    logic/scene/figure/figure.cpp \
    logic/file_readers/filereader.cpp \
    logic/scene/builder/graphbuilder.cpp \
    logic/normalizationparameters.cpp \
    logic/scene/camera/orthogonal.cpp \
    logic/scene/camera/perspective.cpp \
    logic/scene/drawers/scenedrawerbase.cpp \
    main.cpp \
    mainwindow.cpp \
    logic/math/matrix.cpp \
    logic/math/matrixbuilder.cpp \
    logic/math/point.cpp \
    normalizationdialog.cpp \
    qtscenedrawer.cpp \
    logic/scene/scene.cpp \
    logic/scene/figure/components/vertex.cpp

HEADERS += \
    logic/exceptions/base_app_exception.h \
    logic/file_readers/basefilereader.h \
    logic/scene/figure/components/edge.h \
    logic/exceptions/filenotopenedexception.h \
    logic/exceptions/incorrectfileexception.h \
    logic/exceptions/incorrectindexexception.h \
    logic/exceptions/incorrectsize.h \
    logic/exceptions/scenenotloadedexception.h \
    logic/facade.h \
    logic/scene/figure/figure.h \
    logic/scene/builder/figurebuilder.h \
    logic/file_readers/filereader.h \
    logic/scene/builder/graphbuilder.h \
    logic/normalizationparameters.h \
    logic/scene/camera/orthogonal.h \
    logic/scene/camera/perspective.h \
    logic/scene/camera/projection.h \
    mainwindow.h \
    logic/math/matrix.h \
    logic/math/matrixbuilder.h \
    logic/math/point.h \
    normalizationdialog.h \
    qtscenedrawer.h \
    logic/scene/scene.h \
    logic/scene/drawers/scenedrawerbase.h \
    logic/scene/sceneobject.h \
    logic/scene/figure/components/vertex.h

FORMS += \
    forms/mainwindow.ui \
    forms/normalizationdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
