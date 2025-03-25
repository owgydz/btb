# CMakeLists.txt for unittests
# DO NOT TREAT THIS AS THE MAIN PROJECT CMAKE!!!!
find_package(GTest REQUIRED)


add_executable(run_tests
    unittests/cliut.cpp
    unittests/deps_ut.cpp
    unittests/runnerut.cpp
    unittests/inter_ut.cpp
)

target_link_libraries(run_tests GTest::GTest GTest::Main)
