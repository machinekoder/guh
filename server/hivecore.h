#ifndef HIVECORE_H
#define HIVECORE_H

#include <QObject>

class JsonRPCServer;
class DeviceManager;

class HiveCore : public QObject
{
    Q_OBJECT
public:
    static HiveCore* instance();

    DeviceManager* deviceManager() const;

private:
    explicit HiveCore(QObject *parent = 0);
    static HiveCore *s_instance;

    JsonRPCServer *m_jsonServer;
    DeviceManager *m_deviceManager;

private slots:
    void gotSignal(const QUuid &triggerId, const QVariantMap &params);

};

#endif // HIVECORE_H