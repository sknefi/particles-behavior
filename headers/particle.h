//
// Created by Filip Karika on 04/07/2024.
//

#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct {
	float   x;
	float   y;
	float   vx;
	float   vy;
	float   r;
} Particle;

Particle	init_particle(float x, float y, float vx, float vy, float r);
void		show_particle(Particle particle);


#endif //PARTICLE_H
