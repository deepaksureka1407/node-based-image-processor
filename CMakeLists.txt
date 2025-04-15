cmake_minimum_required(VERSION 3.16)

project(NodeImageEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# ✅ Set path to OpenCV if not found automatically
set(OpenCV_DIR "C:/opencv/build")  # main build dir, not /lib or /cmake
set(OpenCV_INCLUDE_DIRS "C:/opencv/build/include")
set(OpenCV_LIB_DIR "C:/opencv/build/x64/mingw/lib")
file(GLOB OpenCV_LIBS "${OpenCV_LIB_DIR}/*.a")  # MinGW static libs

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})


# ✅ Set Qt6 components you need
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

# ✅ Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    nodes/*.cpp
)

file(GLOB_RECURSE HEADERS
    src/*.h
    nodes/*.h
)

# ✅ Create executable
add_executable(NodeImageEditor ${SOURCES} node_image_editor.cpp)

# ✅ Link OpenCV
target_include_directories(NodeImageEditor PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(NodeImageEditor PRIVATE ${OpenCV_LIBS})

# ✅ Link Qt
target_link_libraries(NodeImageEditor PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)

# ✅ Qt UI Definitions (if you use .ui files)
# qt_wrap_ui(UI_HEADERS src/mainwindow.ui)

# ✅ Enable autogen for Qt MOC, UIC, RCC
set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
