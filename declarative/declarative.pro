TEMPLATE = lib

CONFIG += qt \
    plugin \
    link_pkgconfig

INCLUDEPATH += ../bluez-qt
LIBS += -L../bluez-qt

equals(QT_MAJOR_VERSION, 4) {
    QT += declarative dbus
    LIBS += -lbluez-qt
} else {
    QT += qml dbus
    LIBS += -lbluez-qt5
}

TARGET = Bluez-qt
OBJECTS_DIR = .obj
MOC_DIR = .moc

# Input
SOURCES += components.cpp

OTHER_FILES += qmldir

HEADERS += components.h

qmldir.files += qmldir
equals(QT_MAJOR_VERSION, 4): qmldir.path = $$[QT_INSTALL_IMPORTS]/Bluetooth
equals(QT_MAJOR_VERSION, 5): qmldir.path = $$[QT_INSTALL_QML]/Bluetooth

equals(QT_MAJOR_VERSION, 4): target.path = $$[QT_INSTALL_IMPORTS]/Bluetooth
equals(QT_MAJOR_VERSION, 5): target.path = $$[QT_INSTALL_QML]/Bluetooth

INSTALLS += qmldir target
