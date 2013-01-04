TEMPLATE = lib
QT += declarative dbus

CONFIG += qt \
    plugin \
    link_pkgconfig

INCLUDEPATH += ../bluez-qt
LIBS += -L../bluez-qt -lbluez-qt

TARGET = Bluez-qt
OBJECTS_DIR = .obj
MOC_DIR = .moc

# Input
SOURCES += components.cpp

OTHER_FILES += qmldir

HEADERS += components.h

qmldir.files += qmldir
qmldir.path = $$[QT_INSTALL_IMPORTS]/Bluetooth

target.path = $$[QT_INSTALL_IMPORTS]/Bluetooth

INSTALLS += qmldir target
