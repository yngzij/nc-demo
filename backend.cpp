#include "backend.h"

#include "data/global.h"


Backend::Backend(QObject *parent) : QObject(parent) {

}

void Backend::cppFunction(const QList<QUrl> &urls) {
    qDebug() << "cppFunction called";
    for (auto url: urls) {
        qDebug() << url;
    }
    current_urls = urls;
}
