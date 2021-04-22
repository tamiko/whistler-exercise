cmake_minimum_required(VERSION 3.5)
project(mpi-example CXX)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

add_executable(mpi_example mpi_example.cxx)

target_link_libraries(mpi_example ${MPI_CXX_LIBRARIES} ${MPI_LIBRARIES})
set_target_properties(mpi_example PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
set_target_properties(mpi_example PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
