#ifdef __cplusplus
extern "C" {
#endif

#include "user_def.h"

#ifndef UINT8_MAX
	typedef int uint8_t;
#endif

#ifndef OWN_TYPE
	typedef int a_type;
#else
	typedef OWN_TYPE a_type;
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 10
#endif

	struct average {
		uint8_t max_size;
		uint8_t written_samples;
		a_type buffer[MAX_SIZE];
	};

	typedef struct average average;

	void mov_avg_init(average* avg);
	void mov_avg_push(average* avg, a_type element);
	void mov_avg_clear(average* avg);
	a_type mov_avg_get(average* avg);

#ifdef __cplusplus
}
#endif