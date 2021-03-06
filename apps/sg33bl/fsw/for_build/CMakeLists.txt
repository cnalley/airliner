
add_airliner_app_def(sg33bl
    FILE SG33BL
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_config_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_symbols.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_events.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_custom.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_msg.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_tbldefs.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_version.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115_custom.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115_map.h

    INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/

    USER_DOCS   ${CMAKE_CURRENT_SOURCE_DIR}/user_doxy.in
    DESIGN_DOCS ${CMAKE_CURRENT_SOURCE_DIR}/detail_doxy.in

    MSG_OVERRIDES   ${CMAKE_CURRENT_SOURCE_DIR}/sg33bl_msg_overrides.json 

    COMMANDER_PLUGIN
        ${CMAKE_CURRENT_SOURCE_DIR}/../../cdr
)

add_airliner_app_unit_test(sg33bl-ut
    UTASSERT
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_app_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_app_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_cmds_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_cmds_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_config_tbl_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_config_tbl_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_testrunner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_test_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/sg33bl_test_utils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_config_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_events.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_msg.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_tbldefs.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/sg33bl_version.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115_custom.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ads1115_map.h

    INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/
        
    VALGRIND_SUPPRESSION_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/valgrind.supp
)
