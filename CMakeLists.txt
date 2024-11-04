cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Функция для проверки наличия пакета через apt
function(check_apt_package pkg)
    execute_process(
        COMMAND dpkg -s ${pkg}
        RESULT_VARIABLE pkg_not_found
        OUTPUT_QUIET
        ERROR_QUIET
    )
    if (pkg_not_found)
        message(FATAL_ERROR "Package ${pkg} is not installed. Please install it with 'sudo apt install ${pkg}'")
    else()
        message(STATUS "Package ${pkg} is installed.")
    endif()
endfunction()

# Проверка необходимых пакетов
check_apt_package(libginac-dev)
check_apt_package(libgtkmm-3.0-dev)
check_apt_package(libglu1-mesa-dev)
check_apt_package(libopengl-dev)


# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# sudo apt install libgtkmm-3.0-dev libginac-dev libcairomm-1.0-dev freeglut3-dev libglu1-mesa-dev
# Используем pkg-config для нахождения ginac
find_package(PkgConfig REQUIRED)
pkg_check_modules(GINAC REQUIRED ginac)
pkg_check_modules(CAIROMM REQUIRED cairomm-1.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Добавляем все файлы из src и src/core
file(GLOB SRC_FILES
    src/*.cpp
    src/core/*.cpp
)

# Указываем заголовочные файлы (опционально)
file(GLOB HEADER_FILES
    src/*.h
    src/core/*.h
)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()


# Создаем исполняемый файл
add_executable(MyBinary ${SRC_FILES} ${HEADER_FILES})

target_include_directories(MyBinary PRIVATE ${GINAC_INCLUDEDIR}/ginac ${CAIROMM_INCLUDE_DIRS} ${GTKMM_INCLUDE_DIRS})
target_link_libraries(MyBinary ${GINAC_LIBRARIES} ${CAIROMM_LIBRARIES} ${GTKMM_LIBRARIES} pthread -lGL -lglut -lGLU)

# Включаем директории для поиска заголовочных файлов
target_include_directories(MyBinary PRIVATE src src/core)
