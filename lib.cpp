#include "widgets.hpp"

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

int argc = 1;
char* argv[] = {""};

struct Application* Application_New() {
    return reinterpret_cast<Application*>(new QApplication(argc, argv));
}

const char* Object_GetClassName(struct Object* object) {
    return (reinterpret_cast<QObject*>(object))->metaObject()->className() + 1;
}

struct Widget* Widget_New(struct Widget* parent) {
    auto widget = new QWidget(reinterpret_cast<QWidget*>(parent));
    return reinterpret_cast<Widget*>(widget);
}

struct VBoxLayout* VBoxLayout_New(struct Widget* parent) {
    auto layout = new QVBoxLayout(reinterpret_cast<QWidget*>(parent));
    return reinterpret_cast<VBoxLayout*>(layout);
}

void Widget_SetLayout(struct Widget* widget, struct Layout* layout) {
    reinterpret_cast<QWidget*>(widget)->setLayout(reinterpret_cast<QLayout*>(layout));
}

struct Label* Label_New(struct Widget* parent) {
    auto label = new QLabel(reinterpret_cast<QWidget*>(parent));
    return reinterpret_cast<Label*>(label);
}

void Label_SetText(struct Label* label, const char * text) {
    reinterpret_cast<QLabel*>(label)->setText(QString::fromUtf8(text));
}

void Layout_AddWidget(struct Layout* layout, struct Widget* widget) {
    reinterpret_cast<QLayout*>(layout)->addWidget(reinterpret_cast<QWidget*>(widget));
}

struct PushButton* PushButton_New(struct Widget* parent) {
    auto button = new QPushButton(reinterpret_cast<QWidget*>(parent));
    return reinterpret_cast<PushButton*>(button);
}

void PushButton_SetText(struct PushButton* button, const char * text) {
    reinterpret_cast<QPushButton*>(button)->setText(QString::fromUtf8(text));
}

void Widget_SetWindowTitle(struct Widget* widget, const char * text) {
    reinterpret_cast<QWidget*>(widget)->setWindowTitle(QString::fromUtf8(text));
}

void Widget_SetSize(struct Widget* widget, int width, int height) {
    reinterpret_cast<QWidget*>(widget)->setFixedSize(width, height);
}

void Widget_SetVisible(struct Widget* widget, bool visible) {
    reinterpret_cast<QWidget*>(widget)->setVisible(visible);
}

int Application_Exec(Application* app) {
    return reinterpret_cast<QApplication*>(app)->exec();
}

void Object_Delete(Object* object) {
    delete reinterpret_cast<QObject*>(object);
}

void PushButton_SetOnClicked(struct PushButton* button, void (*func)(struct Object*)) {
    QObject::connect(
            reinterpret_cast<QPushButton*>(button),
            &QPushButton::clicked,
            [=](){
                func((struct Object*)button);
            }
    );
}
