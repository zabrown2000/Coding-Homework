#include "Officer.h"

/// <summary>
/// ctor for officer class
/// </summary>
/// <param name="id">int</param>
/// <param name="first">string</param>
/// <param name="last">string</param>
/// <param name="ops">int</param>
/// <param name="score">int</param>
Officer::Officer(int id, string first, string last, int ops, int score) : m_socioScore(score), Soldier(id, first, last, ops) {}

/// <summary>
/// method that checks whether the soldier is entitled to a medal
/// </summary>
/// <returns>bool</returns>
bool Officer::medal() {
	/*Participated in more than 2 military operations and received a sociometric score from the soldiers of at least 92*/
	if ((m_socioScore >= 92) && (m_numOps > 2)) {
		return true;
	}
	return false;
}

/// <summary>
/// method for printing soldier data
/// </summary>
void Officer::print() {

	cout << "officer\n";
	Soldier::print(); //printing overlapping fields

	cout << "sociometric score: " << m_socioScore << endl;
}

/// <summary>
/// method to return score
/// </summary>
/// <returns>int</returns>
int Officer::getSociometric() const {
	return m_socioScore;
}