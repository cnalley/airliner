set(APP_NAME camio)

add_airliner_app_table(
    ${APP_NAME}
    NAME camio_config
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/camio_config.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)


add_airliner_app_unit_test_src(${APP_NAME} SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/camio_config.c)