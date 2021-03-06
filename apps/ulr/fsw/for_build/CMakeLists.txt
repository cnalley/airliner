
add_airliner_app_def(ulr
    FILE ULR
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_events.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_msg.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_symbols.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_version.h

    INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/

    USER_DOCS   ${CMAKE_CURRENT_SOURCE_DIR}/user_doxy.in
    DESIGN_DOCS ${CMAKE_CURRENT_SOURCE_DIR}/detail_doxy.in

    MSG_OVERRIDES ${CMAKE_CURRENT_SOURCE_DIR}/ulr_msg_overrides.json

    COMMANDER_PLUGIN
        ${CMAKE_CURRENT_SOURCE_DIR}/../../cdr
    
    REFERENCE_CONFIG
        ${PROJECT_SOURCE_DIR}/apps/ulr/fsw/mission_inc
        ${PROJECT_SOURCE_DIR}/apps/ulr/fsw/platform_inc

)

add_airliner_app_unit_test(ulr-ut
    UTASSERT
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_app_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_app_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_cmds_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_cmds_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_testrunner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_test_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/ulr_test_utils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/stubs/ut_ulr_custom_hooks.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/stubs/ut_ulr_custom_hooks.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/stubs/ut_ulr_custom_stubs.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/stubs/ut_ulr_custom_stubs.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_events.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_msg.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ulr_version.h
        ${PX4LIB_LIB_SOURCES}

    INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/

    VALGRIND_SUPPRESSION_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/valgrind.supp
)
