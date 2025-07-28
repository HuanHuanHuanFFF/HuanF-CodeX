cmake_minimum_required(VERSION 3.30)
project(HuanF_CodeX LANGUAGES CXX)

# 要求 C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 自动递归搜集本项目所有 .cpp（含子目录）
file(GLOB_RECURSE PROJECT_SOURCES
        "${CMAKE_SOURCE_DIR}/*.cpp"
)

# 生成可执行文件，所有 .cpp 都会编译进来
add_executable(HuanF_CodeX ${PROJECT_SOURCES})

# 确保使用 C++23
target_compile_features(HuanF_CodeX PUBLIC cxx_std_23)
