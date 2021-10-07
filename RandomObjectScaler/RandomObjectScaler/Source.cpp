#define EXPORT_API __declspec(dllexport)

#include <random>
#include <time.h>

// Link following functions C-style (required for plugins)
extern "C"
{
	struct Vector3 {
		float x;
		float y;
		float z;
	};

	struct Vector3I {
		float x;
		float y;
		float z;
	};

	Vector3 lowerBound = { 0.f, 0.f, 0.f };
	Vector3 upperBound = { 2.f, 2.f, 2.f };

	//checks and also resets rand seed
	void EXPORT_API SetScaleBounds(Vector3 lower, Vector3 upper) {
		if (lower.x > upper.x || lower.y > upper.y || lower.z > upper.z) {
			return;
		}
		lowerBound = lower;
		upperBound = upper;
		srand(time(0));
	}

	Vector3 FetchRandomScale() {
		return {
			lowerBound.x + (rand() % int(upperBound.x)),
			lowerBound.y + (rand() % int(upperBound.y)),
			lowerBound.z + (rand() % int(upperBound.z)),
		};
	}
}