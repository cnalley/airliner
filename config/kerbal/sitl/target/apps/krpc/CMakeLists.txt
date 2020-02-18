set(APP_NAME krpc)

add_airliner_app_table(
    ${APP_NAME}
    NAME krpc_config
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/krpc_config.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)
