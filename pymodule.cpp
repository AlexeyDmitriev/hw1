extern "C" {
#include <Python.h>
}
#include "widgets.hpp"
#include <cstdint>

extern "C" {
PyObject* Wrapper_Application_New(PyObject* module, PyObject* args)
{
    if (!PyArg_ParseTuple(args, "")) {
        return nullptr;
    }
    struct Application* app = Application_New();
    std::uintptr_t int_repr = reinterpret_cast<std::uintptr_t>(app);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Wrapper_Object_GetClassName(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric;
    if (!PyArg_ParseTuple(args, "l", &object_numeric)) {
        return nullptr;
    }
    Object* object_ptr = reinterpret_cast<Object*>(object_numeric);
    const char* name = Object_GetClassName(object_ptr);
    PyObject * py_result = PyUnicode_FromString(name);
    return py_result;
}

PyObject* Wrapper_Widget_New(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    if (!PyArg_ParseTuple(args, "|l", &object_numeric)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    struct Widget* widget = Widget_New(object_ptr);
    std::uintptr_t int_repr = reinterpret_cast<std::uintptr_t>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Wrapper_VBoxLayout_New(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    if (!PyArg_ParseTuple(args, "|l", &object_numeric)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    struct VBoxLayout* widget = VBoxLayout_New(object_ptr);
    std::uintptr_t int_repr = reinterpret_cast<std::uintptr_t>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Wrapper_Widget_SetLayout(PyObject* module, PyObject* args)
{
    std::uintptr_t widget_numeric = 0;
    std::uintptr_t layout_numeric = 0;
    if (!PyArg_ParseTuple(args, "ll", &widget_numeric, &layout_numeric)) {
        return nullptr;
    }
    Widget* widget = reinterpret_cast<Widget*>(widget_numeric);
    Layout* layout = reinterpret_cast<Layout*>(layout_numeric);
    Widget_SetLayout(widget, layout);
    Py_RETURN_NONE;
}

PyObject* Wrapper_Label_New(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    if (!PyArg_ParseTuple(args, "|l", &object_numeric)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    struct Label* widget = Label_New(object_ptr);
    std::uintptr_t int_repr = reinterpret_cast<std::uintptr_t>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Wrapper_Label_SetText(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    const char *text;
    if (!PyArg_ParseTuple(args, "ls", &object_numeric, &text)) {
        return nullptr;
    }
    Label* object_ptr = reinterpret_cast<Label*>(object_numeric);
    Label_SetText(object_ptr, text);
    Py_RETURN_NONE;
}

PyObject* Wrapper_Layout_AddWidget(PyObject* module, PyObject* args)
{
    std::uintptr_t int_arg1_repr = 0;
    std::uintptr_t int_arg2_repr = 0;
    if (!PyArg_ParseTuple(args, "ll", &int_arg1_repr, &int_arg2_repr)) {
        return nullptr;
    }
    Layout* object1_ptr = reinterpret_cast<Layout*>(int_arg1_repr);
    Widget* object2_ptr = reinterpret_cast<Widget*>(int_arg2_repr);
    Layout_AddWidget(object1_ptr, object2_ptr);
    Py_RETURN_NONE;
}

PyObject* Wrapper_PushButton_New(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    if (!PyArg_ParseTuple(args, "|l", &object_numeric)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    struct PushButton* widget = PushButton_New(object_ptr);
    std::uintptr_t int_repr = reinterpret_cast<std::uintptr_t>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Wrapper_PushButton_SetText(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    const char *text;
    if (!PyArg_ParseTuple(args, "ls", &object_numeric, &text)) {
        return nullptr;
    }
    PushButton* object_ptr = reinterpret_cast<PushButton*>(object_numeric);
    PushButton_SetText(object_ptr, text);
    Py_RETURN_NONE;
}

PyObject* Wrapper_Widget_SetWindowTitle(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    const char *text;
    if (!PyArg_ParseTuple(args, "ls", &object_numeric, &text)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    Widget_SetWindowTitle(object_ptr, text);
    Py_RETURN_NONE;
}

PyObject* Wrapper_Widget_SetSize(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    int width;
    int height;
    if (!PyArg_ParseTuple(args, "lii", &object_numeric, &width, &height)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    Widget_SetSize(object_ptr, width, height);
    Py_RETURN_NONE;
}

PyObject* Wrapper_Widget_SetVisible(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    int visibility;
    if (!PyArg_ParseTuple(args, "li", &object_numeric, &visibility)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(object_numeric);
    Widget_SetVisible(object_ptr, visibility);
    Py_RETURN_NONE;
}

PyObject* Wrapper_Application_Exec(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric = 0;
    if (!PyArg_ParseTuple(args, "l", &object_numeric)) {
        return nullptr;
    }
    Application* object_ptr = reinterpret_cast<Application*>(object_numeric);
    std::uintptr_t return_code = Application_Exec(object_ptr);
    PyObject * py_result = PyLong_FromLong(return_code);
    return py_result;
}

PyObject* Wrapper_Object_Delete(PyObject* module, PyObject* args)
{
    std::uintptr_t object_numeric;
    if (!PyArg_ParseTuple(args, "l", &object_numeric)) {
        return nullptr;
    }
    Object* object_ptr = reinterpret_cast<Object*>(object_numeric);
    Object_Delete(object_ptr);
    Py_RETURN_NONE;
}

struct RefCountedPyObject {
    PyObject* object;
    ~RefCountedPyObject() {
        Py_XDECREF(object);
    }
    RefCountedPyObject(PyObject* object): object(object) {
        Py_XINCREF(object);
    }
    RefCountedPyObject(const RefCountedPyObject& o): object(o.object) {
        Py_XINCREF(object);
    }
};

PyObject* Wrapper_PushButton_SetOnClicked(PyObject* module, PyObject* args) {
    std::uintptr_t object_numeric;
    PyObject* function;
    if (!PyArg_ParseTuple(args, "lO", &object_numeric, &function)) {
        return nullptr;
    }
    if (!PyCallable_Check(function)) {
        PyErr_SetString(PyExc_TypeError, "parameter must be callable");
        return nullptr;
    }
    RefCountedPyObject obj(function);
    PushButton* object_ptr = reinterpret_cast<PushButton*>(object_numeric);
    PushButton_SetOnClickedCpp(object_ptr, [=]() {
        PyObject_CallObject(obj.object, nullptr);
    });
    Py_RETURN_NONE;
}

PyMODINIT_FUNC PyInit__pywidgets() {

    static PyMethodDef methods[] = {
        {"Application_New", Wrapper_Application_New, METH_VARARGS, ""},
        {"Object_GetClassName", Wrapper_Object_GetClassName, METH_VARARGS, ""},
        {"Widget_New", Wrapper_Widget_New, METH_VARARGS, ""},
        {"VBoxLayout_New", Wrapper_VBoxLayout_New, METH_VARARGS, ""},
        {"Widget_SetLayout", Wrapper_Widget_SetLayout, METH_VARARGS, ""},
        {"Label_New", Wrapper_Label_New, METH_VARARGS, ""},
        {"Label_SetText", Wrapper_Label_SetText, METH_VARARGS, ""},
        {"Layout_AddWidget", Wrapper_Layout_AddWidget, METH_VARARGS, ""},
        {"PushButton_New", Wrapper_PushButton_New, METH_VARARGS, ""},
        {"PushButton_SetText", Wrapper_PushButton_SetText, METH_VARARGS, ""},
        {"Widget_SetWindowTitle", Wrapper_Widget_SetWindowTitle, METH_VARARGS, ""},
        {"Widget_SetSize", Wrapper_Widget_SetSize, METH_VARARGS, ""},
        {"Widget_SetVisible", Wrapper_Widget_SetVisible, METH_VARARGS, ""},
        {"Application_Exec", Wrapper_Application_Exec, METH_VARARGS, ""},
        {"Object_Delete", Wrapper_Object_Delete, METH_VARARGS, ""},
        {"PushButton_SetOnClicked", Wrapper_PushButton_SetOnClicked, METH_VARARGS, ""},
        {nullptr, nullptr, 0, nullptr}
    };

    static PyModuleDef modDef = {
        PyModuleDef_HEAD_INIT,
        "_pywidgets",
        "",
        -1,
        methods
    };

    PyObject* mod = PyModule_Create(&modDef);
    return mod;
}
}
