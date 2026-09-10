#include <string>
#include <vector>

/**
 * Small LP solver for flux-balance problems with equality constraints and
 * variable bounds.
 *
 * It solves:
 *   maximize/minimize c^T v
 *   subject to A v = 0
 *              lb <= v <= ub
 *
 * using basis enumeration over bounded vertices. This is practical for the
 * small metabolic models currently exercised by the runtime tests and provides
 * a concrete solver-backed replacement for the previous stub objective logic.
 */

/**
* interface for MFB Solvers
* strategy design pattern
*/

class MetabolicFluxBalanceSolver_if {
public:
	struct Problem {
		std::vector<std::vector<double>> stoichiometry;
		std::vector<double> lowerBounds;
		std::vector<double> upperBounds;
		std::vector<double> objective;
		bool maximize = true;
	};

	struct Solution {
		bool feasible = false;
		double objectiveValue = 0.0;
		std::vector<double> fluxes;
		std::string errorMessage;
	};

public:
	virtual ~MetabolicFluxBalanceSolver_if() = default;

	virtual Solution solve(const Problem& problem) = 0;
};
