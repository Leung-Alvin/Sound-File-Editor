#ifndef ECHO_H
#define ECHO_H
#include <vector>

class Echo{
public:
    /**
     * used to process the sound data (float vector) and create an echo that repeats
     * @param input: float vector of sound data to be echo processed
     * @param gain: float representing how much the echo's amplitude should be as it decays
     * @param delay: integer represents the number of samples to wait before echoing
     */
	static std::vector<float> process(const std::vector<float>&input, float gain, int delay);
};

#endif
