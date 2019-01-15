QT += widgets
requires(qtConfig(treeview))

FORMS       = mainwindow.ui
HEADERS     = mainwindow.h \
              treeitem.h \
              treemodel.h \
    mysortfilter.h
RESOURCES   = editabletreemodel.qrc
SOURCES     = mainwindow.cpp \
              treeitem.cpp \
              treemodel.cpp \
              main.cpp \
    mysortfilter.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/editabletreemodel
INSTALLS += target
