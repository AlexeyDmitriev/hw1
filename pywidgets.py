#!/usr/bin/env python3

from _pywidgets import *

class Object:
    def __del__(self):
        # Object_Delete(self.ptr)
        pass
    def get_class_name(self):
        return Object_GetClassName(self.ptr)

class Application(Object):
    def __init__(self):
        self.ptr = Application_New()
    def exec(self):
        Application_Exec(self.ptr)

class Widget(Object):
    def __init__(self, parent=None):
        self.ptr = Widget_New(parent.ptr if parent else 0)
    def set_layout(self, layout):
        Widget_SetLayout(self.ptr, layout.ptr)
    def set_window_title(self, text):
        Widget_SetWindowTitle(self.ptr, text)
    def set_size(self, width, height):
        Widget_SetSize(self.ptr, width, height)
    def set_visible(self, visibility):
        Widget_SetVisible(self.ptr, visibility)

class Layout(Widget):
    def add_widget(self, widget):
        Layout_AddWidget(self.ptr, widget.ptr)

class VBoxLayout(Layout):
    def __init__(self, parent=None):
        self.ptr = VBoxLayout_New(parent.ptr if parent else 0)

class Label(Widget):
    def __init__(self, parent=None):
        self.ptr = Label_New(parent.ptr if parent else 0)
    def set_text(self, text):
        Label_SetText(self.ptr, text)

class PushButton(Widget):
    def __init__(self, parent=None):
        self.ptr = PushButton_New(parent.ptr if parent else 0)
    def set_text(self, text):
        PushButton_SetText(self.ptr, text)
    def set_on_clicked(self, listener):
        PushButton_SetOnClicked(self.ptr, lambda: listener(self))
