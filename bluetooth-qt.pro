!exists(bluemanager.h):system(qdbusxml2cpp -p bluemanager.h:bluemanager.cpp manager.xml)
!exists(blueadapter.h):system(qdbusxml2cpp -p blueadapter.h:blueadapter.cpp adapter.xml)
!exists(bluedevice.h):system(qdbusxml2cpp -p bluedevice.h:bluedevice.cpp -i devicetypes.h device.xml)
!exists(audiosink.h):system(qdbusxml2cpp -p audiosink.h:audiosink.cpp audiosink.xml)
!exists(audiosource.h):system(qdbusxml2cpp -p audiosource.h:audiosource.cpp audiosrc.xml)
!exists(headset.h):system(qdbusxml2cpp -p headset.h:headset.cpp headset.xml)
include(obex/obex.pri)

