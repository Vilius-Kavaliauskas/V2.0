#pragma once
#ifndef STUDENTAS_STRUCT_H
#define STUDENTAS_STRUCT_H

#include <string>
#include <vector>
#include <numeric>

struct Studentas_struct
{
	std::string vardas;
	std::string pavarde;
	double egz;
	std::vector<double> nd;
	double galutinis;

	bool operator < (Studentas_struct& s2) const
	{
		if (galutinis > s2.galutinis) { return true; }
		else if (galutinis < s2.galutinis) { return false; }
		else
		{
			if (pavarde > s2.pavarde) { return true; }
			else if (pavarde < s2.pavarde) { return false; }
		}
	}

	double balas()
	{
		galutinis = 0.4 * (std::accumulate(nd.begin(), nd.end(), 0.0) / nd.size()) + 0.6 * egz;
		return galutinis;
	}
};

#endif // !STUDENTAS_STRUCT_H
