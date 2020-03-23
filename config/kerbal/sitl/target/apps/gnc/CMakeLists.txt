set(APP_NAME gnc)

add_airliner_app_table(
    ${APP_NAME}
    NAME gnc_config
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/gnc_config.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)
