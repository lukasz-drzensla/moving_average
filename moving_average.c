#include "moving_average.h"

#ifdef __cplusplus
extern "C" {
#endif

	void mov_avg_init(average* avg)
	{
		avg->max_size = MAX_SIZE;
		avg->written_samples = 0;
		memset(avg->buffer, 0, sizeof(avg->buffer));
	}

	void mov_avg_push(average* avg, a_type element)
	{
		if (avg->written_samples < avg->max_size)
		{
			//if not full yet - fill
			avg->buffer[avg->written_samples] = element;
			++avg->written_samples;
		}
		else {
			//shift left the buffer
			for (uint8_t i = 1; i < avg->max_size; i++)
			{
				avg->buffer[i - 1] = avg->buffer[i];
			}
			//put the new element as last
			avg->buffer[avg->max_size-1] = element;
		}
	}

	void mov_avg_clear(average* avg)
	{
		mov_avg_clear(avg);
	}

	a_type mov_avg_get(average* avg) 
	{
		a_type temp = 0;
		uint8_t samples = avg->written_samples;
		for (uint8_t i = 0; i < samples; i++)
		{
			temp += avg->buffer[i];
		}
		return temp / samples;
	}

#ifdef __cplusplus
}
#endif