include(FetchContent)
set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_NETWORK OFF)
set(SFML_BUILD_DOC OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_TEST_SUITE OFF)
set(BUILD_SHARED_LIBS FALSE)
set(SFML_USE_STATIC_STD_LIBS TRUE)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    OVERRIDE_FIND_PACKAGE)
FetchContent_MakeAvailable(SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

#set(SFML_STATIC_LIBRARIES TRUE)
#list(APPEND CMAKE_MODULE_PATH "${SFML_BINARY_DIR}")
#set(SFML_DIR "${SFML_BINARY_DIR}")
#set(SFML_ROOT "${SFML_BINARY_DIR}")

set(CSFML_BUILD_AUDIO ON)
set(CSFML_BUILD_NETWORK OFF)
set(CSFML_BUILD_DOC OFF)
set(CSFML_BUILD_EXAMPLES OFF)
set(CSFML_BUILD_TEST_SUITE OFF)
set(CSFML_USE_STATIC_STD_LIBS TRUE)
set(LINK_STATICALLY_DEFAULT TRUE)
FetchContent_Declare(CSFML
    GIT_REPOSITORY https://github.com/SFML/CSFML.git
    GIT_TAG 2.6.1)
FetchContent_MakeAvailable(CSFML)
target_link_libraries(${PROJECT_NAME} PRIVATE
    csfml-graphics
    csfml-window
    csfml-system
    csfml-audio
)

#-DSFML_ROOT="$SFML_PATH" -DSFML_INCLUDE_DIR="$SFML_PATH/include" -DCMAKE_MODULE_PATH="$SFML_PATH/cmake/Modules" .
#LD_LIBRARY_PATH="$SFML_PATH/lib"
