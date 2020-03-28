
add_airliner_app_def(krpc
    FILE KRPC
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_config_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_events.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_msg.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_tbldefs.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_version.h
   
    INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/
        ${CMAKE_CURRENT_SOURCE_DIR}/../public_inc/

    USER_DOCS   ${CMAKE_CURRENT_SOURCE_DIR}/user_doxy.in
    DESIGN_DOCS ${CMAKE_CURRENT_SOURCE_DIR}/detail_doxy.in
)

target_link_libraries(krpc PRIVATE -Wl,-rpath=/usr/local/lib -lkrpc -lprotobuf)

add_airliner_app_unit_test(krpc-ut
    UTASSERT
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_app_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_app_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_cmds_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_cmds_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_config_tbl_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_config_tbl_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_testrunner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_test_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/krpc_test_utils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_config_utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_events.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_msg.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_tbldefs.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/krpc_version.h
        
    INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/
        ${CMAKE_CURRENT_SOURCE_DIR}/../public_inc/
        
    VALGRIND_SUPPRESSION_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/../unit_test/valgrind.supp
)

