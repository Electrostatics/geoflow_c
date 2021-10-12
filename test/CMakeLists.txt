# Googletest needs C++11
set(CMAKE_CXX_STANDARD 11)

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
	# This is gross, but I've already spent far too long on hacking CMake.
	# Hopefully Erik can come in and make this pretty.
	${geoflow_c_SOURCE_DIR}/src/Atom.cpp
	Atom_test.cpp
	#solvationsub_test.cpp
	#surfconcz_test.cpp
)

target_link_libraries(UnitTests gmock_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)
