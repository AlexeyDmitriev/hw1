extern "C" {
#include "widgets.h"
}
#include <QObject>
#include <QPushButton>

template<typename T>
void PushButton_SetOnClickedCpp(struct PushButton* button, T t) {
    QObject::connect((struct QPushButton*)(struct QObject*) button, &QPushButton::clicked, t);
}

