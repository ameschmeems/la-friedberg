add_executable(ex1-2-3)

target_sources(ex1-2-3
	PRIVATE
		main.cpp
)

target_link_libraries(ex1-2-3 PRIVATE core)