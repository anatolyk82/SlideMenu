#ifndef MYDEVICE_H
#define MYDEVICE_H

#include <QObject>
#include <QScreen>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#ifdef Q_OS_ANDROID
#include <QtAndroidExtras>
#endif


class MyDevice : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isMobile READ isMobile NOTIFY isMobileChanged)
    Q_PROPERTY(qreal dp READ dp NOTIFY dpChanged)

public:
    explicit MyDevice(QObject *parent = 0);
    ~MyDevice();

    Q_INVOKABLE qreal dp( int value ) { return m_dp*value; }

    bool isMobile() const { return m_isMobile; }
    qreal dp() const { return m_dp; }

signals:

    void isMobileChanged(bool arg);
    void dpChanged(qreal arg);

public slots:

private:
    bool m_isMobile;
    QScreen *m_screen;
    int m_dpi;
    qreal m_dp;
};

#endif // MYSCREEN_H
