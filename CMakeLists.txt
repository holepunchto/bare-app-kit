cmake_minimum_required(VERSION 4.0)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-fetch REQUIRED PATHS node_modules/cmake-fetch)
find_package(cmake-prelude REQUIRED PATHS node_modules/cmake-prelude)

project(bare_app_kit LANGUAGES C OBJC VERSION 0.3.4)

fetch_package("github:holepunchto/bare@1.38.0" SOURCE_DIR bare)
fetch_package("github:holepunchto/libpath")

add_bare_module(bare_app_kit)

target_sources(
  ${bare_app_kit}
  PRIVATE
    binding.m
)

target_include_directories(
  ${bare_app_kit}
  PRIVATE
    node_modules/bare-foundation-registry/lib
)

target_link_libraries(
  ${bare_app_kit}
  PUBLIC
    "-framework AppKit"
    "-framework UniformTypeIdentifiers"
)

bare_target(target)

add_executable_target(
  bare_runtime
  SOURCES
    lib/runtime.m
  LINK
    $<LINK_LIBRARY:WHOLE_ARCHIVE,bare_static>
    rlimit_static
    path_static
    "-framework AppKit"
  EXPORTS_FROM
    "${bare}/src/exports.json"
  RPATH
    ../Frameworks
  DESTINATION
    "${target}"
  EXPORT OFF
)

set_target_properties(
  bare_runtime_executable
  PROPERTIES
  C_STANDARD 99
  OBJC_STANDARD 99
  POSITION_INDEPENDENT_CODE ON
  OUTPUT_NAME bare
  BUILD_WITH_INSTALL_RPATH ON
)
