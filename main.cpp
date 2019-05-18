#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <sndfile.h>
#include <filework.h>
#include <modelplayer.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<FileWork>("module", 1, 0, "FileWork");

    ModelPlayer player;


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mediaPlayer", &player);

    engine.load(QUrl(QStringLiteral("../AudioPlauer/PlayerClassic.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
