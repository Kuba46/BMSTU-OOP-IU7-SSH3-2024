QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logic/src/calculator.cpp \
    logic/src/commands/operatorcommand.cpp \
    logic/src/commands/push_command_to_stack.cpp \
    logic/src/facade.cpp \
    main.cpp \
    mainwindow.cpp \
    logic/src/operators/add.cpp \
    logic/src/operators/divide.cpp \
    logic/src/operators/minus.cpp \
    logic/src/operators/multiply.cpp \
    logic/src/operators/operatorcreator.cpp \
    logic/src/parser.cpp \
    logic/src/translator.cpp \
    logic/src/validator.cpp

HEADERS += \
    configurations.h \
    exceptions/invalid_expression_exception.hpp \
    exceptions/unknown_operator_exception.hpp \
    logic/include/calculator.h \
    logic/include/commands/command.hpp \
    logic/include/commands/operatorcommand.h \
    logic/include/commands/push_command_to_stack.h \
    logic/include/facade.h \
    mainwindow.h \
    logic/include/operators/add.h \
    logic/include/operators/divide.h \
    logic/include/operators/minus.h \
    logic/include/operators/multiply.h \
    logic/include/operators/operator.h \
    logic/include/operators/operatorcreator.h \
    logic/include/parser.h \
    logic/include/translator.h \
    logic/include/validator.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
