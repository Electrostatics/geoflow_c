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
     )

#
#  build standalone C example
#
add_executable(GeometricFlowWrap
     runGeometricFlowWrap.cpp
)

target_link_libraries(GeometricFlow GeometricFlowLib)
target_link_libraries(GeometricFlowWrap GeometricFlowLib)

install(TARGETS GeometricFlowLib GeometricFlow GeometricFlowWrap)
