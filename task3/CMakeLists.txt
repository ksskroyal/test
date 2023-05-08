cmake_minimum_required(VERSION 3.1)
project(task2)


set(SERVER ./src/server.cpp ./src/myjson.cpp ./src/generator.cpp  ./src/CookingRecipe.cpp)
set(CLIENT ./src/client.cpp src/CookingRecipe.cpp)

include_directories(./inc)
include_directories(./ext/cpp-httplib-master)
add_subdirectory(./ext/nlohmann)

add_executable(server ${SERVER})

add_executable(client ${CLIENT})

add_custom_command(
TARGET server
POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy
${CMAKE_SOURCE_DIR}/data/RecipeNames.txt
${CMAKE_CURRENT_BINARY_DIR}/RecipeNames.txt
)

add_custom_command(
TARGET server
POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy
${CMAKE_SOURCE_DIR}/data/Ingrediens.txt
${CMAKE_CURRENT_BINARY_DIR}/Ingrediens.txt
)


target_link_libraries(server nlohmann_json)
target_link_libraries(client nlohmann_json)
