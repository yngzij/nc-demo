#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <asio.hpp>
#include <QThread>


#include "TcpServer.h"
#include "backend.h"


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    asio::io_context io_context;
    TcpServer server(io_context, 8888);
    server.accept();
    std::thread t([&io_context]() {
        io_context.run();
    });

    t.detach();


    QQmlApplicationEngine engine;

    Backend backend;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("backend", &backend);

    //engine.rootContext()->setContextProperty("backend", &backend);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
