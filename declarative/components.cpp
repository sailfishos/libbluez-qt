/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include "components.h"

#include <nearbydevicesmodel.h>
#include <bluetoothdevice.h>
#include <bluetoothdevicemodel.h>

void Components::registerTypes(const char *uri)
{
    qmlRegisterType<NearbyDevicesModel>(uri,0,0,"NearbyDevicesModel");
    qmlRegisterType<BluetoothDevice>(uri,0,0,"BluetoothDevice");
    qmlRegisterType<BluetoothDevicesModel>(uri,0,0,"BluetoothDevicesModel");
}

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
Q_EXPORT_PLUGIN(Components);
#endif
