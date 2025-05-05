// #include "myitemmodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
    #include <QQmlContext>
#include"myproxymodel.h"


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);


    // MyItemModel myitemmodel; /*= new MyItemModel();*/
    myproxymodel myitemmodel;


    // qmlRegisterSingletonInstance("mymodel",1,0,"MyItemModel",&myitemmodel);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/untitled/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("myitemmodel", &myitemmodel);
    engine.load(url);

    return app.exec();
}
