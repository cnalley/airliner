set(APP_NAME lc)

add_airliner_app_table(
    ${APP_NAME}
    NAME lc_def_adt
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/lc_def_adt.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_airliner_app_table(
    ${APP_NAME}
    NAME lc_def_wdt
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/lc_def_wdt.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_airliner_app_unit_test_src(
    ${APP_NAME}
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/lc_custom.c
)