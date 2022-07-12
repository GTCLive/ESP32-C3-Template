
set(srcs "driver.c"
    )
    
    
idf_component_register(
	SRCS ${srcs}
    INCLUDE_DIRS
        "."
    PRIV_INCLUDE_DIRS
    REQUIRES
    PRIV_REQUIRES
)