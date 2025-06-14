cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME fbttf)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
SET(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(WITH_PIC "Build with position independent code" ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Flash Back To The Future"
    LANGUAGES C
)

include(GNUInstallDirs)

# if(MSVC)
#     set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
# else()
#     set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#     set(CMAKE_EXE_LINKER_FLAGS "-static")
# endif()

# ----------------------------------------------------------------------------

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets/" DESTINATION "share/${PROJECT_NAME}")

add_executable(
    ${PROJECT_NAME}
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

add_subdirectory(deps)

# Clang-Tidy

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")

if(CLANG_TIDY_EXE)
    if (NOT DEFINED NO_USE_CLANG_TIDY)
        if (MSVC)
            add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/.clang-tidy
                COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy
            ${CMAKE_BINARY_DIR}/.clang-tidy
            )
            set_target_properties(${PROJECT_NAME_CLIENT} PROPERTIES
                VS_GLOBAL_RunCodeAnalysis true
                VS_GLOBAL_EnableClangTidyCodeAnalysis true
                VS_GLOBAL_ClangTidyChecks "-checks=-*,clang-diagnostic-*,clang-analyzer-*,-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,modernize-*,portability-*,readability-*,-readability-identifier-length,-modernize-use-trailing-return-type"
            )
            set_target_properties(${PROJECT_NAME_SERVER} PROPERTIES
                VS_GLOBAL_RunCodeAnalysis true
                VS_GLOBAL_EnableClangTidyCodeAnalysis true
                VS_GLOBAL_ClangTidyChecks "-checks=-*,clang-diagnostic-*,clang-analyzer-*,-*,clang-analyzer-*,concurrency-*,cppcoreguidelines-*,modernize-*,portability-*,readability-*,-readability-identifier-length,-modernize-use-trailing-return-type"
            )
        else()
            set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "--fix" "--fix-notes" "--fix-errors")
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
        endif()
    endif()
endif()

# Add server or client definitions

if(DEFINED PACKAGED)
    target_compile_definitions(
        ${PROJECT_NAME}
        PUBLIC
        PACKAGED
    )
endif()

# Add compile options

if(MSVC)
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        /W4
    )
else()
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
        -Wall -Wextra -pedantic
    )
endif()

# -- This definition specifies the minimum Windows version required for compilation
# -- Avoids boost warnings
# -- In this case, Windows 7
#if (WIN32)
#  add_definitions(-D_WIN32_WINNT=0x0601)
#endif()

add_subdirectory(src)
add_subdirectory(lib)

if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${PROJECT_NAME}>
        ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.exe
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${PROJECT_NAME}>
        "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.exe"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${PROJECT_NAME}>
        "${CMAKE_BINARY_DIR}/Release/${PROJECT_NAME}.exe"
    )
else()
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${PROJECT_NAME}>
        ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${PROJECT_NAME}>
        "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}"
    )
endif()

# ----------------------------------------------------------------------------
# CPACK

set(CPACK_PACKAGE_VENDOR "X-L-R-G-B")

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "Fbttf")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CMAKE_SYSTEM_NAME}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CMAKE_SYSTEM_NAME}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# NSIS
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/favicon.ico")
set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/favicon.ico")
set(CPACK_NSIS_PACKAGE_NAME "Fbttf")

set(CPACK_RESOURCE_FILE_WELCOME "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
if(NOT WIN32)
    set(CPACK_PACKAGE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/favicon.bmp")
endif()
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Fbttf")
set(CPACK_CREATE_DESKTOP_LINKS ${PROJECT_NAME})
set(CPACK_PACKAGE_EXECUTABLES ${PROJECT_NAME} "Fbttf")

list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.git/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/CMakeFiles/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/_CPack_Packages/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/bin(ary)?/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/build/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/dist/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/libs?/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/logs?/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/objs?/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/[tT]e?mp/")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/___pycache__")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.cache")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/\.gitignore.*")
list(APPEND CPACK_SOURCE_IGNORE_FILES "/CMakeCache.txt")
list(APPEND CPACK_SOURCE_IGNORE_FILES "\.pyc$")
list(APPEND CPACK_SOURCE_IGNORE_FILES "\.swp$")
list(APPEND CPACK_SOURCE_IGNORE_FILES "~$")


include(CPack)
