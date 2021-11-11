include(FetchContent)
# google test commit e2239ee = v1.11.0
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(
	${geoflow_c_SOURCE_DIR}/src
	${googletest_SOURCE_DIR}/googlemock/include
)

add_executable(UnitTests test_main.cpp
	Atom_test.cpp
	#solvationsub_test.cpp
	#surfconcz_test.cpp
)

target_link_libraries(UnitTests gmock_main GeometricFlowLib)

include(GoogleTest)
gtest_discover_tests(UnitTests)
