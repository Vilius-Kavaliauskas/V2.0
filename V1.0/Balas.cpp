#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#include "Studentas.h"

void balas(std::string tipas, std::vector <studentas>& stud)
{
    int kiek = stud.size();
    for (int i = 0; i < kiek; i++)
    {
        studentas laikinas = stud[i];
        if (tipas == "V")
        {
            laikinas.galutinis = 0.4 * (std::accumulate(laikinas.nd.begin(), laikinas.nd.end(), 0.0) / laikinas.nd.size()) + 0.6 * laikinas.egz;
        }

        else if (tipas == "M")
        {
            std::sort(laikinas.nd.begin(), laikinas.nd.end());
            int vid = laikinas.nd.size();
            if (vid % 2 != 0) { laikinas.galutinis = laikinas.nd[vid / 2] * 0.4 + laikinas.egz * 0.6; }
            else { laikinas.galutinis = (laikinas.nd[vid / 2] + laikinas.nd[vid / 2 - 1]) / 2 * 0.4 + 0.6 * laikinas.egz; }
        }

        stud[i] = laikinas;
    }
}