cmake_minimum_required(VERSION 2.6)

project(M1_ISI_isiviewer-1.2)

# For eclipse to resolve all include files
# Ubuntu 12.04
include_directories(/usr/include)
include_directories(/usr/include/i386-linux-gnu)
include_directories(/usr/include/c++/4.6/i686-linux-gnu)
include_directories(/usr/lib/gcc/i686-linux-gnu/4.6/include)
#include_directories(/usr/include/c++/4.6)

# Ubuntu 11.04
#include_directories(/usr/include)
#include_directories(/usr/include/c++/4.5)
#include_directories(/usr/lib/x86_64-linux-gnu/gcc/x86_64-linux-gnu/4.5/include)
#include_directories(/usr/include/c++/4.5/x86_64-linux-gnu/)

find_package(Qt4)
set(QT_USE_QTXML 1)
set(QT_USE_QTOPENGL 1)
include(${QT_USE_FILE})

include_directories(glm ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})

# Generate header files from qt designer ui files
set(UIC_IN  my_gui_form.ui)
qt4_wrap_ui(UIC_OUT ${UIC_IN})

# Generate cpp files from header files containing Q_OBJECT macro
set(MOC_IN my_main_window.h my_scene.h)
qt4_wrap_cpp(MOC_OUT ${MOC_IN})

set(SOURCES ${UIC_OUT} ${MOC_OUT} 
            my_qglviewer.cpp my_main_window.cpp my_scene.cpp my_object3d.cpp 
            main.cpp objects/triMesh.cpp objects/cube.cpp objects/pyramid.cpp 
            objects/disk.cpp objects/partialdisk.cpp objects/cylinder.cpp 
            objects/cone.cpp objects/sphere.cpp objects/func_surface.cpp 
            objects/off_loader.cpp config.cpp objects/sphere_subdiv.cpp Bench.cpp)

add_executable(isiviewer ${SOURCES})

target_link_libraries (isiviewer GLEW ${QT_LIBRARIES} QGLViewer) 

# add a symbolic link toward the source directory
add_custom_command(TARGET isiviewer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
  )

