#include <QGuiApplication>
#include <QQuickItem>
#include <QQmlEngine>
#include <QQuickView>
#include <QQmlContext>


#include <QTranslator>
#include <QTextCodec>
#include <QLocale>
#include <QDir>

#include "qtquick2applicationviewer.h"

//#include "qmlapplicationviewer.h"
#include "gnupgconnector.h"
#include "mailreader.h"
#include "configuration.h"


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    //QScopedPointer<QApplication> app(createApplication(argc, argv));
    //QScopedPointer<QGuiApplication> app(Sailfish::createApplication(argc, argv));
    QGuiApplication app(argc, argv);
    // i18n stuff
    qDebug() << "I18N: local:" << QLocale::system().name();
    QString locale = QLocale::system().name();
    QString filename = QString("languages/languages/lang_") + locale;

    // Data for Settings
    QCoreApplication::setOrganizationName("chrmSoft");
    QCoreApplication::setOrganizationDomain("chrm.info");
    QCoreApplication::setApplicationName("CryptMee");


    static QTranslator translator;
    if( translator.load(filename, ":/") ){
        app.installTranslator(&translator);
        // QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8")); // use default coded instead
        qDebug() << "I18N: Translation file loaded" << filename;
    } else
        qDebug() << "I18N: Translation file not loaded:" << filename;


    // Register C++ class
    qmlRegisterType<GnuPGConnector>("GnuPGConnector", 1, 0, "GnuPGConnector");
    qmlRegisterType<MailReader>("MailReader", 1, 0, "MailReader");

    QtQuick2ApplicationViewer viewer;
    QQmlContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("Release_Version", RELEASE);
    ctxt->setContextProperty("GnuPG_PATH", GPGBIN);
    ctxt->setContextProperty("GnuPG_TMPFILE", TMPFILE);
    ctxt->setContextProperty("GnuPG_KEYSERVER", KEYSERVER);
    ctxt->setContextProperty("MAIL_PATH", MAIL_PATH);
    ctxt->setContextProperty("MAIL_DB", MAIL_DB);
    ctxt->setContextProperty("TMP_DIR", TMP_DIR);


    viewer.setMainQmlFile(QLatin1String("qml/CryptMee/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
