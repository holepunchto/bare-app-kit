cmake_minimum_required(VERSION 4.0)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-fetch REQUIRED PATHS node_modules/cmake-fetch)
find_package(cmake-prelude REQUIRED PATHS node_modules/cmake-prelude)

project(bare_app_kit C OBJC)

fetch_package("github:holepunchto/bare@1.38.0")
fetch_package("github:holepunchto/libpath#a68d099")

add_bare_module(
  bare_app_kit
  SOURCES
    binding.m
  LINK
    "-framework AppKit"
    "-framework UniformTypeIdentifiers"
)

target_include_directories(
  ${bare_app_kit}
  PRIVATE
    node_modules/bare-foundation-registry/lib
)

bare_target(target)

add_executable_target(
  bare_runtime
  SOURCES
    lib/runtime.m
  LINK
    $<LINK_LIBRARY:WHOLE_ARCHIVE,bare::static>
    bare::exports
    rlimit::static
    path::static
    "-framework AppKit"
  EXPORTS
    bare_native_terminates_after_last_window_closed
  RPATH ../Frameworks
  DESTINATION ${target}
  OUTPUT_DIRECTORY bin
  EXPORT OFF
)

set_target_properties(
  bare_runtime_executable
  PROPERTIES
  OUTPUT_NAME bare
)
