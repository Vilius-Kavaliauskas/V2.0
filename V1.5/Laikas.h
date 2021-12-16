#ifndef  LAIKAS_H
#define LAIKAS_H

#include <chrono>
/// Laikmacio funkcija.
class laikas {
private:
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	std::chrono::time_point<hrClock> start;
public:
	/// Konstruktorius, su kuriuo pagal nutylejima paleidziamas laikmatis.
	laikas() : start{ hrClock::now() } {}

	/// Laikamcio atstatymas.
	void reset() {
		start = hrClock::now();
	}

	/// Rezultato spausdinimo funkcija.
	double elapsed() const {
		return durationDouble(hrClock::now() - start).count();
	}
};

#endif // ! LAIKAS_H

