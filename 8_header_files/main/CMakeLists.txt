idf_component_register(
    SRCS 
        "8_header_files.c"
        "calc/calc.c" # adding this new file
    INCLUDE_DIRS
         "."
         "./calc" # adding a subdirectory
)
