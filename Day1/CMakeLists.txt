set(PROJECT_NAME Day1)

file(GLOB SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        )

add_executable(${PROJECT_NAME} ${SRCS} ray.h hittable.h sphere.h hittable_list.h rtweekend.h camera.h material.h lambertian.h metal.h)