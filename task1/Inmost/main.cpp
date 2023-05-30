#include "inmost.h"
#include <iostream>
#include <chrono>

using namespace INMOST;
using namespace std;
        
int main(int argc, char **argv) {
	Solver::Initialize(&argc, &argv);

	Sparse::Matrix A;
	A.Load("/home/sergey/cmc/6sem/SVT/task1/Inmost_task/A_tet3.mtx");
	cout << "Размер системы: " << A.Size() << "\n";

	Sparse::Vector rhs;
	rhs.Load("/home/sergey/cmc/6sem/SVT/task1/Inmost_task/rhs_tet3.mtx");

	std::string drop_tolerance(argv[1]);

	Solver S(Solver::INNER_ILU2);
	S.SetParameter("verbosity", "3");
	S.SetParameter("drop_tolerance", drop_tolerance);
	
	auto start = std::chrono::steady_clock::now(); 
	S.SetMatrix(A);
	auto end = std::chrono::steady_clock::now();
	cout << "Time in milliseconds for ILU(2):" << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "\n";


	Sparse::Vector sol(rhs);
	start = std::chrono::steady_clock::now();
	bool solved = S.Solve(rhs, sol);
	end = std::chrono::steady_clock::now();
	cout << "Time in milliseconds for BiCGStab:" << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "\n";

	std::cout << "Number of iterations: " << S.Iterations() << std::endl;
	std::cout << "Residual: " << S.Residual() << std::endl;
	Solver::Finalize();
	return 0;
}
