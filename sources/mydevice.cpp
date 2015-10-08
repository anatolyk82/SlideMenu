#include "mydevice.h"


MyDevice::MyDevice(QObject *parent) : QObject(parent)
{
    m_screen = qApp->primaryScreen();
    m_dpi = m_screen->physicalDotsPerInch() * m_screen->devicePixelRatio();
    m_isMobile = false;
#if defined(Q_OS_IOS)
    m_dpi = m_screen->physicalDotsPerInch();
    m_isMobile = true;
#elif defined(Q_OS_ANDROID)
    QAndroidJniEnvironment env;
    QAndroidJniObject activity = QtAndroid::androidActivity();
    QAndroidJniObject resources = activity.callObjectMethod("getResources", "()Landroid/content/res/Resources;");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();

        //return EXIT_FAILURE;
    }

    QAndroidJniObject displayMetrics = resources.callObjectMethod("getDisplayMetrics", "()Landroid/util/DisplayMetrics;");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();

        //return EXIT_FAILURE;
    }
    m_dpi = displayMetrics.getField<int>("densityDpi");
    m_isMobile = true;

#else
    // standard dpi
    m_dpi = m_screen->logicalDotsPerInch() * m_screen->devicePixelRatio();
#endif
    m_dp = m_dpi / 160.f;
    emit dpChanged(m_dp);
    emit isMobileChanged(m_isMobile);
    //qDebug() << "*** dp:"<<m_dp<<" dpi:"<<m_dpi;
}

MyDevice::~MyDevice()
{
}



