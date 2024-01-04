#ifndef BACKEND_H
#define BACKEND_H


#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QList>


class Backend : public QObject {
Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE static void cppFunction(const QList<QUrl> &urls);

};


#endif // BACKEND_H
