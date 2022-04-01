include(FetchContent)
# google test commit e2239ee = v1.11.0
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if(Apple)
	find_package(Intl REQUIRED)
	find_package(Iconv REQUIRED)
    list(APPEND APBS_LIBS 
        ${Intl_LIBRARIES}
        ${Iconv_LIBRARIES}
    )
    set(MORE_INCLUDE_DIRS
        ${Intl_INCLUDE_DIRS}
        ${Iconv_INCLUDE_DIRS}
    )
    if(MORE_INCLUDE_DIRS)
        include_directories(${MORE_INCLUDE_DIRS})
    endif()
    message(STATUS "()()()() Iconv_LIBRARIES: ${Iconv_LIBRARIES}")
endif()

include_directories(
	${geoflow_c_SOURCE_DIR}/src
	${googletest_SOURCE_DIR}/googlemock/include
)

add_executable(UnitTests test_main.cpp
	Atom_test.cpp
	#solvationsub_test.cpp
	#surfconcz_test.cpp
)

target_link_libraries(UnitTests 
	gmock_main 
	GeometricFlowLib 
)
if(Apple)
	target_link_libraries(UnitTests
		"-framework CoreFoundation"
	)
endif()

include(GoogleTest)
gtest_discover_tests(UnitTests)
