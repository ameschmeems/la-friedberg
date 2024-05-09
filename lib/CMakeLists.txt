add_library(core)

target_include_directories(core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(core PRIVATE ${PROJECT_SOURCE_DIR}/lib)

target_compile_features(core PUBLIC cxx_std_14)

file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")

add_subdirectory(fields)

target_sources(core
	PRIVATE
		utils.cpp
		utils.hpp
)