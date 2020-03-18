#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>
#include <bdlbsc/module/web/WebDataComponent.h>

int main(int argc, char *argv[]) {

  QtWebEngine::initialize();

  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  qmlRegisterType<bdlbsc::WebDataComponent>("WebDataComponent", 1, 0,
                                            "WebDataComponent");
  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
