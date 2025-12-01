cmake_minimum_required(VERSION 4.0)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-fetch REQUIRED PATHS node_modules/cmake-fetch)

project(bare_app_kit C OBJC)

fetch_package("github:holepunchto/bare@1.24.5")
fetch_package("github:holepunchto/libpath")

add_executable(bare_runtime)

target_sources(
  bare_runtime
  PRIVATE
    lib/runtime.m
)

set(bare_runtime_rpath "@loader_path/../Frameworks")

set_target_properties(
  bare_runtime
  PROPERTIES
  C_STANDARD 99
  OBJC_STANDARD 99
  POSITION_INDEPENDENT_CODE ON
  OUTPUT_NAME bare
  INSTALL_RPATH "${bare_runtime_rpath}"
  BUILD_WITH_INSTALL_RPATH ON
  ENABLE_EXPORTS ON
)

target_link_libraries(
  bare_runtime
  PUBLIC
    $<LINK_LIBRARY:WHOLE_ARCHIVE,bare_static>
  PRIVATE
    log_static
    rlimit_static
    path_static
)

target_link_libraries(
  bare_runtime
  PRIVATE
    "-framework AppKit"
)

bare_target(target)

install(TARGETS bare_runtime RUNTIME DESTINATION ${target})
