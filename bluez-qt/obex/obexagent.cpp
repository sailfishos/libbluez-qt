/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c ObexAgentAdaptor -a obexagent.h:obexagent.cpp agent.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "obexagent.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class ObexAgentAdaptor
 */

ObexAgentAdaptor::ObexAgentAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

ObexAgentAdaptor::~ObexAgentAdaptor()
{
    // destructor
}

void ObexAgentAdaptor::Complete(const QDBusObjectPath &path)
{
    // handle method call org.bluez.obex.Agent.Complete
    QMetaObject::invokeMethod(parent(), "Complete", Q_ARG(QDBusObjectPath, path));
}

void ObexAgentAdaptor::Error(const QDBusObjectPath &path, const QString &error)
{
    // handle method call org.bluez.obex.Agent.Error
    QMetaObject::invokeMethod(parent(), "Error", Q_ARG(QDBusObjectPath, path), Q_ARG(QString, error));
}

void ObexAgentAdaptor::Progress(const QDBusObjectPath &path, qulonglong transferred)
{
    // handle method call org.bluez.obex.Agent.Progress
    QMetaObject::invokeMethod(parent(), "Progress", Q_ARG(QDBusObjectPath, path), Q_ARG(qulonglong, transferred));
}

void ObexAgentAdaptor::Release()
{
    // handle method call org.bluez.obex.Agent.Release
    QMetaObject::invokeMethod(parent(), "Release");
}

