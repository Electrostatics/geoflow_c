#
#  build geoflow library
#
add_library(GeometricFlowLib 
     GeometricFlowWrap.cpp
     GeometricFlow.cpp
     Atom.cpp
     )

#
#  build standalone C++ example
#
add_executable(GeometricFlow 
     runGeometricFlow.cpp
     GeometricFlow.cpp
     Atom.cpp
     )

#
#  build standalone C example
#
add_executable(GeometricFlowWrap
     runGeometricFlowWrap.c
)

target_link_libraries(GeometricFlowWrap GeometricFlowLib)
add_dependencies(GeometricFlow eigen3 boost)
add_dependencies(GeometricFlowLib eigen3 boost)
add_dependencies(GeometricFlowWrap eigen3 boost)

