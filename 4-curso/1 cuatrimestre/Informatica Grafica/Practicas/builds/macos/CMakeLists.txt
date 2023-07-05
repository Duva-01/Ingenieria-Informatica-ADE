## --------------------------------------------------------------------------------
## Prácticas de Informática Gráfica, curso 22-23
##
## Archivo de configuración para compilar usando CMake en macOS
## última modificación: 14-Julio de 2022
##
## --------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.5.1)
project (pracs_ig_macos_exe)

##
## Opciones para el compilador (configurables)
##

set (opcs_warnings "-Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field" )
set (opcs_primer_error "-Wfatal-errors")

##
## Paths a las distintas carpetas
##

set (raiz       "../..")
set (rec_src    ${raiz}/materiales/src-cpp)
set (rec_inc    ${raiz}/materiales/src-cpp)
set (alu_src    ${raiz}/src)
set (alu_inc    ${raiz}/src)
set (ejecutable "pracs_ig_macos_exe")

##
##  definir flags para compilador y enlazador
##  (dependen del sistema operativo, en este caso macOS)
##

##add_definitions (-DOSX)
set (flags_compilador "-std=c++11 -g -I/usr/local/include ${opcs_warnings} ${opcs_primer_error}")  ## hace falta /usr/local/include ??
set (flags_enlazador "")
link_directories( /usr/local/lib )
find_library( ogllib OpenGL )

##
## Directorios para ejecutable y los flags de compila
##

##set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${raiz}/${diralu}/bin")  ## el binario lo dejamos en 'cmake-unix/build'
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flags_compilador}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${flags_enlazador}")

##
## definir donde están las unidades de compilación y los headers

file (GLOB alu_units ${alu_src}/*.cpp)
file (GLOB alu_headers ${alu_inc}/*.h)
file (GLOB rec_units ${rec_src}/*.cpp)
file (GLOB rec_headers ${rec_inc}/*.h)

## NOTA: se excluyen archivos de la carpeta de alumnos ('trabajo') cuyo 
## nombre comienze por 'ex' (PELIGROSO!) (no lo hago: peligroso!)
##
##list (FILTER alu_headers EXCLUDE REGEX "\/ex[^.]*\.h$")
##list (FILTER alu_units EXCLUDE REGEX "\/ex[^.]*\.cpp$")


##
## definir el ejecutable y los directorios de include
##

add_executable ( ${ejecutable} ${alu_units} ${rec_units} ${alu_headers} ${rec_headers})
target_include_directories ( ${ejecutable} PUBLIC ${alu_inc} ${rec_inc})
target_link_libraries( ${ejecutable} glfw jpeg ${ogllib})

## añadir 'custom command' para ejecutar después de creado el ejecutable
## desactivo temoralmente

# add_custom_command(
#     POST_BUILD
#     TARGET  ${ejecutable}
#     COMMAND ./${ejecutable}
#     COMMENT "Ejecutando programa ..... (" ${ejecutable} ")"
# )

##### imprime todas las variables cuando se pone 'cmake .' (activar/desactivar poniendo true/false)

if ( false )
   get_cmake_property(_variableNames VARIABLES)
   list (SORT _variableNames)
   foreach (_variableName ${_variableNames})
      message(STATUS "${_variableName}=${${_variableName}}")
   endforeach()
endif()

