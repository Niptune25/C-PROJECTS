#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"
namespace graphicproj {

class Swarm
{
	public:
		const static int NPARTICLES=90000;
		const Particle *getParticles() {return m_pParticles;};
	private:
		Particle *m_pParticles;
	public:
		Swarm();
		~Swarm();
		void update();
		
};
}

#endif
