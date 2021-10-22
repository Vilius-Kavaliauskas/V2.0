#ifndef  LAIKAS_H
#define LAIKAS_H

#include <chrono>

class laikas {
private:
	// panaudojame using
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	std::chrono::time_point<hrClock> start;
public:
	laikas() : start{ hrClock::now() } {}
	void reset() {
		start = hrClock::now();
	}
	double elapsed() const {
		return durationDouble(hrClock::now() - start).count();
	}
};

#endif // ! LAIKAS_H

