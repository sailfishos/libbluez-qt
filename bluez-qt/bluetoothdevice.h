#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

#include <QObject>
#include <QDBusVariant>
#include <QStringList>

class OrgBluezDeviceInterface;
class OrgBluezAudioInterface;
class OrgBluezHeadsetInterface;
class QDBusPendingCallWatcher;
class QDBusObjectPath;

class BluetoothDevice : public QObject
{
    Q_OBJECT
    Q_ENUMS(AudioConnectionState)
    Q_PROPERTY(bool ready READ ready NOTIFY readyChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(AudioConnectionState audioConnectionState READ audioConnectionState NOTIFY audioConnectionStateChanged)
    Q_PROPERTY(QString address READ address NOTIFY addressChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString icon READ icon NOTIFY nameChanged)
    Q_PROPERTY(quint32 classOfDevice READ classOfDevice NOTIFY classOfDeviceChanged)
    Q_PROPERTY(QStringList profiles READ profiles NOTIFY profilesChanged)
    Q_PROPERTY(bool paired READ paired NOTIFY pairedChanged)
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(bool trusted READ trusted WRITE setTrusted NOTIFY trustedChanged)
    Q_PROPERTY(QString alias READ alias WRITE setAlias NOTIFY aliasChanged)
    Q_PROPERTY(bool legacyPairing READ legacyPairing NOTIFY legacyPairingChanged)

public:
    enum AudioConnectionState {
        AudioStateUnknown,
        AudioConnecting,
        AudioConnected,
        AudioDisconnecting,
        AudioDisconnected
    };

    explicit BluetoothDevice(QObject *parent = 0);
    explicit BluetoothDevice(const QDBusObjectPath &path, QObject *parent = 0);
    ~BluetoothDevice();

    bool ready() const;

    QString path() const;
    void setPath(const QString &path);

    AudioConnectionState audioConnectionState() const;
    bool audioPlayingState() const;

    QString address() const;

    QString name() const;

    QString icon() const;

    quint32 classOfDevice() const;

    QStringList profiles() const;

    bool paired() const;

    bool connected() const;

    bool trusted() const;
    void setTrusted(bool trusted);

    QString alias() const;
    void setAlias(const QString &alias);

    bool legacyPairing() const;

public slots:
    void connectAudio();
    void disconnectAudio();
    void disconnect();

signals:
    void devicePropertiesChanged();

    // deprecated, only used by bluetoothdevicemodel.cpp
    void propertyChanged(const QString &name, const QVariant &variant);

    void readyChanged();
    void pathChanged();
    void audioConnectionStateChanged();
    void audioPlayingStateChanged(bool playing);

    void addressChanged();
    void nameChanged();
    void iconChanged();
    void classOfDeviceChanged();
    void profilesChanged();
    void pairedChanged();
    void connectedChanged();
    void trustedChanged();
    void aliasChanged();
    void legacyPairingChanged();

private slots:
    void getPropertiesFinished(QDBusPendingCallWatcher *call);
    void propertyChanged(QString name, QDBusVariant value);
    void getAudioPropertiesFinished(QDBusPendingCallWatcher *call);
    void audioPropertyChanged(QString name, QDBusVariant value);
    void getIsPlayingFinished(QDBusPendingCallWatcher *call);
    void headsetPropertyChanged(QString name, QDBusVariant value);

private:
    void init();
    bool updateProperty(const QString &name, const QVariant &value);
    void updateAudioProperty(const QString &name, const QVariant &value);
    void updateHeadsetProperty(const QString &name, const QVariant &value);

    OrgBluezDeviceInterface *m_device;
    OrgBluezAudioInterface *m_audio;
    OrgBluezHeadsetInterface *m_headset;
    QVariantMap m_properties;
    QString m_objectPath;
    AudioConnectionState m_audioConnectionState;
    bool m_audioPlayingState;
};

Q_DECLARE_METATYPE(BluetoothDevice::AudioConnectionState)

#endif // BLUETOOTHDEVICE_H
