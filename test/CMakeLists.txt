add_executable(
  MeshesTest
  testCircleClass.cpp
  testCircleClassFixtures.cpp
)

target_link_libraries(
        MeshesTest
        gtest_main
        meshes
)

include(GoogleTest)
gtest_discover_tests(MeshesTest)