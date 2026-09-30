add_executable(LeetCodeSolutions
  quests/maths/l1q1/l1q1_tests.cpp
  quests/maths/l1q2/l1q2_tests.cpp
  quests/maths/l1q3/l1q3_tests.cpp
  quests/maths/l2q1/l2q1_tests.cpp
  quests/maths/l2q2/l2q2_tests.cpp
  quests/maths/l2q3/l2q3_tests.cpp
  quests/maths/l3q1/l3q1_tests.cpp
  quests/maths/l3q2/l3q2_tests.cpp
  quests/maths/l3q3/l3q3_tests.cpp
  quests/maths/l4q1/l4q1_tests.cpp
  quests/data\ structures\ and\ algorithms/l1q1/l1q1_tests.cpp
  quests/data\ structures\ and\ algorithms/l1q2/l1q2_tests.cpp
  quests/data\ structures\ and\ algorithms/l1q3/l1q3_tests.cpp
  quests/data\ structures\ and\ algorithms/l2q1/l2q1_tests.cpp
  quests/data\ structures\ and\ algorithms/l2q2/l2q2_tests.cpp
  quests/data\ structures\ and\ algorithms/l2q3/l2q3_tests.cpp
)

target_include_directories(LeetCodeSolutions
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(LeetCodeSolutions
  PRIVATE
    Catch2::Catch2WithMain
)

# Automatically locate and copy the ASan DLL on Windows
if(WIN32 AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # Ask Clang dynamically where its internal libraries are located
  execute_process(
    COMMAND ${CMAKE_CXX_COMPILER} -print-resource-dir
    OUTPUT_VARIABLE CLANG_RESOURCE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  # Build the path to the ASan DLL relative to the dynamic resource dir
  set(ASAN_DLL "${CLANG_RESOURCE_DIR}/lib/windows/clang_rt.asan_dynamic-x86_64.dll")

  # Copy the DLL into the same folder as the test executable
  if(EXISTS "${ASAN_DLL}")
    add_custom_command(TARGET LeetCodeSolutions POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${ASAN_DLL}"
      $<TARGET_FILE_DIR:LeetCodeSolutions>
      COMMENT "Dynamically copying ASan DLL from compiler resources"
    )
  endif()
endif()

include(CTest)
include(Catch)

# Discover tests and benchmarks inside the single monolithic executable
catch_discover_tests(LeetCodeSolutions)
