cmake_minimum_required(VERSION 2.8)

file(GLOB SRC
    "*.cpp"
)

foreach( sourcefile ${SRC} )
	get_filename_component(testname ${sourcefile} NAME_WE)
	add_executable( ${testname} ${sourcefile} )
endforeach(sourcefile ${SRC} )

