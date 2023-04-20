//
//  double_pendulum.hpp
//  DoublePendulum
//
//  Created by Ethan Quinn on 3/14/23.
//

#ifndef double_pendulum_hpp
#define double_pendulum_hpp

#include <cmath>
#include <utility>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


const float GRAVITY = -9.80665;
const float DT = 0.05;
const float DAMPENING = .997;
const float PI = 3.14159265359;

class pendulum
{
    public:
        pendulum();
        pendulum(std::pair<float, float> _length, std::pair<float, float> _theta, std::pair<float, float> _omega, std::pair<float, float> _mass);
        void update();
        void print();
    private:
        std::pair<float, float> length, theta, omega, mass, xCoordinate, yCoordinate, dydxTheta, dydxOmega;
        std::vector<float> xEndpoints, yEndpoints;
    
};

#endif /* double_pendulum_hpp */
