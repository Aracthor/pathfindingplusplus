project("pathfindingplusplus")

set(ALGO_DIR algo)
set(ALGO_SRCS)
add_subdirectory(${ALGO_DIR})
foreach(file ${ALGO_FILES})
  set(ALGO_SRCS ${ALGO_SRCS} ${ALGO_DIR}/${file})
endforeach()

set(GRAPHICS_DIR graphics)
set(GRAPHICS_SRCS)
add_subdirectory(${GRAPHICS_DIR})
foreach(file ${GRAPHICS_FILES})
  set(GRAPHICS_SRCS ${GRAPHICS_SRCS} ${ALGO_DIR}/${file})
endforeach()


set(SRCS_FILES
  main.cpp
  ${ALGO_SRCS}
  ${GRAPHICS_SRCS}
  PARENT_SCOPE
  )
