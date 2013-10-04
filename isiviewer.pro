TEMPLATE = app
TARGET = 
CONFIG += qt \
    opengl \
    warn_on \
    release \
    thread
QT += xml \
    opengl
FORMS = my_gui_form.ui
HEADERS = my_qglviewer.h \
    my_main_window.h \
    my_scene.h \
    my_object3d.h \
    objects/triMesh.h \
    objects/cube.h \
    objects/cone.h \
    objects/cylinder.h \
    objects/disk.h \
    objects/func_surface.h \
    objects/off_loader.h \
    objects/partialdisk.h \
    objects/pyramid.h \
    objects/sphere_subdiv.h \
    objects/sphere.h \
    Bench.h \
    config.h
SOURCES = my_qglviewer.cpp \
    my_main_window.cpp \
    my_scene.cpp \
    my_object3d.cpp \
    main.cpp \
    objects/triMesh.cpp \
    objects/cube.cpp \
    objects/cone.cpp \
    objects/cylinder.cpp \
    objects/disk.cpp \
    objects/func_surface.cpp \
    objects/off_loader.cpp \
    objects/partialdisk.cpp \
    objects/pyramid.cpp \
    objects/sphere_subdiv.cpp \
    objects/sphere.cpp \
    Bench.cpp \
    config.cpp
INCLUDEPATH += ./glm-0.9.3.4
unix:LIBS *= -lQGLViewer

# Intermediate files are created in a separate folder
MOC_DIR = .moc
OBJECTS_DIR = .obj
