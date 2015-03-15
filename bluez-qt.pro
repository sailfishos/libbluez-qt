TEMPLATE = subdirs
SUBDIRS += bluez-qt declarative tests
CONFIG += ordered

# Adds 'coverage' target
include(coverage.pri)
