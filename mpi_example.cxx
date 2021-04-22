# include <iostream>
# include <mpi.h>
# include <unistd.h>

int main(int argc, char *argv[]) {
  MPI_Init(&argc, &argv);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  unsigned int pid = getpid();

  if (rank != 0) {
    MPI_Send(&pid, 1, MPI_UNSIGNED, /*dest*/ 0, /*tag*/ 0, MPI_COMM_WORLD);

  } else {
    // the main process:

    int n_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &n_processes);

    std::cout << "The number of processes is " << n_processes << std::endl;
    std::cout << "Rank 0 has process id " << pid << std::endl;

    for (unsigned int p = 1; p < n_processes; ++p) {
      MPI_Recv(&pid, 4, MPI_UNSIGNED, p, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      std::cout << "Rank " << p << " has process id " << pid << std::endl;
    }
  }
  MPI_Finalize();
}
